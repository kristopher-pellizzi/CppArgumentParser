#include <iostream>
#include "ArgumentParser.h"

using namespace AP;

ArgumentParser::ArgumentParser(int argc, char** argv) : 
    argc(argc), 
    optional_arg_defs(std::set<ArgumentDefinition>()),
    positional_arg_defs(std::vector<ArgumentDefinition>())
{
    for (int i = 0; i < argc; ++i){
        this->argv.push_back(std::string(argv[i]));
    }
}

ArgumentParser::ArgumentParser(const ArgumentParser& ap) : 
    argc(ap.argc), 
    optional_arg_defs(std::set<ArgumentDefinition>()),
    positional_arg_defs(std::vector<ArgumentDefinition>())
{
    argv = std::vector<string>(ap.argv.begin(), ap.argv.end());
}

ArgumentParser& ArgumentParser::operator=(const ArgumentParser& ap){
    argc = ap.argc;
    argv = std::vector<string>(ap.argv.begin(), ap.argv.end());
    optional_arg_defs = std::set<ArgumentDefinition>();
    positional_arg_defs = std::vector<ArgumentDefinition>();

    return *this;
}

void ArgumentParser::add_optional_arg(ArgumentDefinition& arg){
    optional_arg_defs.insert(arg);
}

void ArgumentParser::add_positional_arg(ArgumentDefinition& arg){
    positional_arg_defs.push_back(arg);
}

void ArgumentParser::add_argument(string name, string value, string help_string){
    ArgumentDefinition arg(name, value, help_string);

    if(arg.is_optional())
        add_optional_arg(arg);
    else
        add_positional_arg(arg);
}

void ArgumentParser::parse_args() const{

}