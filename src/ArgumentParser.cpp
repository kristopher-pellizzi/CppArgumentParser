#include <iostream>
#include "ArgumentParser.h"
#include "errors/UnknownArgumentException.h"
#include "errors/TooManyArgumentsException.h"
#include "errors/TooFewArgumentsException.h"

using namespace AP;

ArgumentParser::ArgumentParser(int argc, char** argv) : 
    argc(argc), 
    optional_arg_defs(std::set<ArgumentDefinition, std::less<>>()),
    positional_arg_defs(std::vector<ArgumentDefinition>()),
    num_parsed_positional_args(0),
    parsed_arguments(std::map<string, Argument>())
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
    parsed_arguments(std::map<string, Argument>())
{
    argv = std::vector<string>(ap.argv.begin(), ap.argv.end());
}

ArgumentParser& ArgumentParser::operator=(const ArgumentParser& ap){
    argc = ap.argc;
    argv = std::vector<string>(ap.argv.begin(), ap.argv.end());
    optional_arg_defs = std::set<ArgumentDefinition, std::less<>>();
    positional_arg_defs = std::vector<ArgumentDefinition>();
    num_parsed_positional_args = 0;
    parsed_arguments = std::map<string, Argument>();

    return *this;
}

void ArgumentParser::add_optional_arg(ArgumentDefinition& arg){
    optional_arg_defs.insert(arg);
    #ifdef DEBUG
    std::cout << "[*] Added optional argument " << arg.get_name() << std::endl;
    #endif
}

void ArgumentParser::add_positional_arg(ArgumentDefinition& arg){
    positional_arg_defs.push_back(arg);
    #ifdef DEBUG
    std::cout << "[*] Added positional argument " << arg.get_name() << std::endl;
    #endif

}

void ArgumentParser::add_argument(string name, string help_string){
    ArgumentDefinition arg(name, help_string);

    if(arg.is_optional())
        add_optional_arg(arg);
    else
        add_positional_arg(arg);
}

void ArgumentParser::parse_optional_arg(string str_arg){
    auto found = optional_arg_defs.find(str_arg);

    if (found == optional_arg_defs.end()){
        throw UnknownArgumentException(str_arg);
    }

    /*
        If str_arg is already inside map parsed_arguments, erase it before
        inserting the new parsed value
    */
    auto parsed_arg = parsed_arguments.find(str_arg);
    if (parsed_arg != parsed_arguments.end())
        parsed_arguments.erase(str_arg);

    string val = argv[++argv_index];
    Argument arg(*found, val);
    parsed_arguments.insert(std::pair<string, Argument>(str_arg, arg));

    #ifdef DEBUG
    std::cout << "[*] Parsed optional argument " << found->get_name() << ". Parsed value: " << arg.get_value() << std::endl;
    #endif
}

void ArgumentParser::parse_positional_arg(string str_arg){;
    ArgumentDefinition& def = positional_arg_defs[num_parsed_positional_args++];

    if (num_parsed_positional_args > positional_arg_defs.size())
        throw TooManyArgumentsException(positional_arg_defs.size(), num_parsed_positional_args);

    Argument arg(def, str_arg);

    parsed_arguments.insert(std::pair<string, Argument>(def.get_name(), arg));

    #ifdef DEBUG
    std::cout << "[*] Parsed positional argument " << def.get_name() << ". Parsed value: " << arg.get_value() << std::endl;
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

    #ifdef DEBUG
    std::cout << "[*] Arguments parsed successfully" << std::endl;
    #endif

    ArgumentsMap ret(parsed_arguments);
    return ret;
}