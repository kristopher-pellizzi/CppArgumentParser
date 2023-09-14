#include <iostream>
#include <cstdarg>
#include <vector>
#include <string>
#include "ArgumentParser.h"
#include "NamedArgumentsParser.h"
#include "errors/UnknownArgumentException.h"
#include "errors/MissingRequiredArgsException.h"
#include "errors/TooManyArgumentsException.h"
#include "errors/TooFewArgumentsException.h"
#include "errors/IncompatibleActionException.h"
#include "errors/UnknownActionException.h"

using namespace AP;
using std::string;

ArgumentParser::ArgumentParser(int argc, char** argv) : 
    argc(argc), 
    optional_arg_defs(std::set<ArgumentDefinition, std::less<>>()),
    positional_arg_defs(std::vector<ArgumentDefinition>()),
    num_parsed_positional_args(0),
    required_opt_parameters(std::set<string>()),
    parsed_arguments(std::map<string, IArgument*>())
{
    for (int i = 0; i < argc; ++i){
        this->argv.push_back(std::string(argv[i]));
    }
}

ArgumentParser::ArgumentParser(const ArgumentParser& ap) : 
    argc(ap.argc), 
    optional_arg_defs(std::set<ArgumentDefinition, std::less<>>()),
    positional_arg_defs(std::vector<ArgumentDefinition>()),
    num_parsed_positional_args(0),
    required_opt_parameters(std::set<string>()),
    parsed_arguments(std::map<string, IArgument*>())
{
    argv = std::vector<string>(ap.argv.begin(), ap.argv.end());
}

ArgumentParser& ArgumentParser::operator=(const ArgumentParser& ap){
    argc = ap.argc;
    argv = std::vector<string>(ap.argv.begin(), ap.argv.end());
    optional_arg_defs = std::set<ArgumentDefinition, std::less<>>();
    positional_arg_defs = std::vector<ArgumentDefinition>();
    num_parsed_positional_args = 0;
    required_opt_parameters = std::set<string>();
    parsed_arguments = std::map<string, IArgument*>();

    return *this;
}

ArgumentParser::~ArgumentParser(){
    for(auto iter = parsed_arguments.begin(); iter != parsed_arguments.end(); ++iter){
        delete (iter->second);
    }
}

void ArgumentParser::add_optional_arg(ArgumentDefinition& arg){
    optional_arg_defs.insert(arg);
    void* def_val = arg.get_default_val();
    IArgument* arg_val = NULL;

    if (def_val != NULL){
        switch (arg.get_action()){
            case ArgumentAction::STORE:
                arg_val = new Argument<string>(arg, * (string*) def_val);
                break;
            case ArgumentAction::APPEND:
                arg_val = new Argument<std::vector<string>>(arg, * (std::vector<string>*) def_val);
                break;
            default:
                throw IncompatibleActionException("Default value is only allowed with actions ArgumentAction::STORE and ArgumentAction::APPEND");
        }

    }
    else{
        switch (arg.get_action()){
            case ArgumentAction::STORE_TRUE:
                arg_val = new Argument<string>(arg, "false");
                break;
            case ArgumentAction::STORE_FALSE:
                arg_val = new Argument<string>(arg, "true");
                break;
            default:
                break;
        }
    }

    if (arg_val != NULL)
        parsed_arguments.insert(std::pair<string, IArgument*>(arg.get_name(), arg_val));

    if (arg.is_required())
        required_opt_parameters.insert(arg.get_name());

    #ifdef DEBUG
    std::cout << "[*] Added optional argument " << arg.get_name() << " with action " << arg.get_action() << std::endl;
    #endif
}

void ArgumentParser::add_positional_arg(ArgumentDefinition& arg){
    positional_arg_defs.push_back(arg);
    #ifdef DEBUG
    std::cout << "[*] Added positional argument " << arg.get_name() << std::endl;
    #endif

}

void ArgumentParser::add_argument(string name, string help_string, string* default_val, bool is_required, ArgumentAction action){
    ArgumentDefinition arg(name, help_string, default_val, is_required, action);

    if(arg.is_optional())
        add_optional_arg(arg);
    else{
        if (action != ArgumentAction::STORE){
            throw IncompatibleActionException("Positional arguments can only use action ArgumentAction::STORE");
        }

        add_positional_arg(arg);
    }
}

void ArgumentParser::add_argument(std::map<string, void*>& args){
    string name;
    string help_string;
    string* default_val;
    bool is_required;
    ArgumentAction action;

    NA::FunctionSignature sig;
    sig.register_argument("name");
    sig.register_argument("help_string", string(""));
    sig.register_argument("default_val", NULL);
    sig.register_argument("is_required", false);
    sig.register_argument("action", ArgumentAction::STORE);

    NA::NamedArgumentsParser parser = NA::NamedArgumentsParser(sig, args);

    parser.get(&name, "name");
    parser.get(&help_string, "help_string");
    parser.get(&default_val, "default_val");
    parser.get(&is_required, "is_required");
    parser.get(&action, "action");

    add_argument(name, help_string, default_val, is_required, action);
}

string ArgumentParser::get_argument_val(const ArgumentDefinition& arg_def) {
    ArgumentAction action = arg_def.get_action();

    switch (action){
        case ArgumentAction::STORE_TRUE:
            return "true";
        case ArgumentAction::STORE_FALSE:
            return "false";
        default:
            return argv[++argv_index];
    }
}

void ArgumentParser::parse_optional_arg(string str_arg){
    auto found = optional_arg_defs.find(str_arg);

    if (found == optional_arg_defs.end()){
        throw UnknownArgumentException(str_arg);
    }

    
    auto parsed_arg = parsed_arguments.find(str_arg);
    string val = get_argument_val(*found);

    if (found->get_action() == ArgumentAction::APPEND){
        std::vector<string> v;

        /*
            If APPEND arg is already inside parsed_arguments, update its list
            and remove the already inserted entry
        */
        if(parsed_arg != parsed_arguments.end()){
            (parsed_arg->second)->get_value(&v);
            v.push_back(val);
            parsed_arguments.erase(parsed_arg);
        }
        /*
            If it is not already there, create a new vector
        */
        else{
            v.push_back(val);
        }

        IArgument* updated = new Argument<std::vector<string>>(*found, v);
        parsed_arguments.insert(std::pair<string, IArgument*>(str_arg, updated));
    }
    else{
        /*
            If str_arg is already inside map parsed_arguments, erase it before
            inserting the new parsed value
        */
        if(parsed_arg != parsed_arguments.end())
            parsed_arguments.erase(str_arg);

        IArgument* arg = new Argument<string>(*found, val);
        parsed_arguments.insert(std::pair<string, IArgument*>(str_arg, arg));
    }

    #ifdef DEBUG
    std::cout << "[*] Parsed optional argument " << found->get_name() << ". Parsed value: " << val << std::endl;
    #endif
}

void ArgumentParser::parse_positional_arg(string str_arg){;
    ArgumentDefinition& def = positional_arg_defs[num_parsed_positional_args++];

    if (num_parsed_positional_args > positional_arg_defs.size())
        throw TooManyArgumentsException(positional_arg_defs.size(), num_parsed_positional_args);

    Argument<string>* arg = new Argument<string>(def, str_arg);

    parsed_arguments.insert(std::pair<string, IArgument*>(def.get_name(), arg));

    #ifdef DEBUG
    std::cout << "[*] Parsed positional argument " << def.get_name() << ". Parsed value: " << str_arg << std::endl;
    #endif
}

void ArgumentParser::parse_arg(string str_arg){
    if(str_arg[0] == '-'){
        parse_optional_arg(str_arg);
    }
    else{
        parse_positional_arg(str_arg);
    }
}

ArgumentsMap ArgumentParser::parse_args(){
    /*
        Start from argv[1], as argv[0] is program's name
    */
    for(argv_index = 1; argv_index < argc; ++argv_index){
        parse_arg(argv[argv_index]);
    }

    if (num_parsed_positional_args < positional_arg_defs.size())
        throw TooFewArgumentsException(positional_arg_defs.size(), num_parsed_positional_args);

    std::set<string> missing_args;
    for(auto iter = required_opt_parameters.begin(); iter != required_opt_parameters.end(); ++iter){
        auto found = parsed_arguments.find(*iter);

        if (found == parsed_arguments.end())
            missing_args.insert(*iter);
    }

    if(missing_args.size() > 0)
        throw MissingRequiredArgsException(missing_args);

    #ifdef DEBUG
    std::cout << "[*] Arguments parsed successfully" << std::endl;
    #endif

    ArgumentsMap ret(parsed_arguments);
    return ret;
}