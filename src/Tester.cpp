#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "ArgumentParser.h"

using std::cout;
using std::endl;

using namespace AP;
using std::stringstream;
using std::string;

string get_list_as_string(std::vector<string>& v){
    if (v.size() == 0)
        return "[]";

    stringstream ss;
    
    ss << "[";
    for(int i = 0; i < v.size() - 1; ++i){
        ss << v[i] << ", ";
    }
    ss << v[v.size() - 1] << "]";

    return ss.str();
}

int main(int argc, char** argv){
    #ifdef DEBUG
    cout << "[*] Creating ArgumentParser..." << endl;    
    #endif
    ArgumentParser parser(argc, argv);
    #ifdef DEBUG
    cout << "[*] ArgumentParser created successfully" << endl;
    #endif

    parser.add_argument(NamedArgument<string>("name", "arg1"));
    parser.add_argument(NamedArgument<string>("name", "--arg2"));
    parser.add_argument(NamedArgument<string>("name", "--Arg4"));
    parser.add_argument(
        NamedArgument<string>("name", "--arg3"),
        NamedArgument<string*>("default_val", new string("Bell'argomento"))
    );
    parser.add_argument(NamedArgument<string>("name", "arg6"));
    parser.add_argument(
        NamedArgument<bool>("is_required", true),
        NamedArgument<string>("name", "--required"),
        NamedArgument<string*>("default_val", new string("Test"))
    );
    parser.add_argument(
        NamedArgument<bool>("is_required", true),
        NamedArgument<string>("name", "--required2")
    );
    parser.add_argument(
        NamedArgument<string>("name", "--list-arg"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND)
    );
    parser.add_argument(
        NamedArgument<string>("name", "--this-is-true"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::STORE_TRUE)
    );
    parser.add_argument(
        NamedArgument<string>("name", "--this-is-false"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::STORE_FALSE)
    );
    parser.add_argument(
        NamedArgument<string>("name", "--list-arg"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND),
        NamedArgument<std::vector<string>*>("default_val", new std::vector<string>{"my", "name", "is", "Kris"})
    );
    parser.add_argument(
        NamedArgument<string>("name", "--another-list"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND),
        NamedArgument<std::vector<string>*>("default_val", new std::vector<string>{"this", "is", "another", "list"})
    );
    parser.add_argument(
        NamedArgument<string>("name", "--required-list"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND),
        NamedArgument<bool>("is_required", true)
    );

    ArgumentsMap args = parser.parse_args();

    std::cout << "Parsed arguments:" << std::endl;

    for(auto iter = args.begin(); iter != args.end(); ++iter){
        string s;
        if ((iter->second)->is_multivalue()){
            std::vector<string> v;
            iter->second->get_value(&v);
            s = get_list_as_string(v);
        }
        else
            (iter->second)->get_value(&s);
        std::cout << "Name: " << iter->first << "; Action: " << iter->second->get_action() << "; Value: " << s << std::endl;
    }

    std::cout << "Trying to access argument by name (--arg2):" << std::endl;
    string s;
    args["--arg2"]->get_value(&s);
    std::cout << "Value: " << s << std::endl;
}