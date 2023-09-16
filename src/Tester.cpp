#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "ArgumentParser.h"
#include "IntConverter.h"

using std::cout;
using std::endl;

using namespace AP;
using std::stringstream;
using std::string;

template <typename T>
string get_list_as_string(std::vector<T>& v){
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
    parser.add_argument(
        NamedArgument<string>("name", "--arg-abbr"),
        NamedArgument<string>("abbreviation", "-t"),
        NamedArgument<string>("help_string", "This is just a test string to check the usage manual is printed correctly")
    );
    parser.add_argument(NamedArgument<string>("name", "--Arg4"));
    parser.add_argument(
        NamedArgument<string>("name", "--arg3"),
        NamedArgument<string*>("default_val", new string("Bell'argomento"))
    );
    parser.add_argument(NamedArgument<string>("name", "arg6"));
    parser.add_argument(
        NamedArgument<bool>("is_required", true),
        NamedArgument<string>("name", "--required"),
        NamedArgument<string*>("default_val", new string("Test")),
        NamedArgument<string>("help_string", "AAAAAAAAAABBBBBBBBBBCCCCCCCCCCDDDDDDDDDDEEEEEEEEEEFFFFFFFFFFGGGGGGGGGGHHHHHHHHHH")
    );
    parser.add_argument(
        NamedArgument<bool>("is_required", true),
        NamedArgument<string>("name", "--required2"),
        NamedArgument<string>("help_string", "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ")
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
        NamedArgument<string>("name", "--unused-true"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::STORE_TRUE)
    );
    parser.add_argument(
        NamedArgument<string>("name", "--this-is-false"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::STORE_FALSE)
    );
    parser.add_argument(
        NamedArgument<string>("name", "--unused-false"),
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
    parser.add_argument(
        NamedArgument<string>("name", "--this-is-optional"),
        NamedArgument<string>("dest", "optional_dest")
    );
    parser.add_argument(
        NamedArgument<string>("name", "this-is-positional"),
        NamedArgument<string>("dest", "positional_dest")
    );
    parser.add_argument(
        NamedArgument<string>("name", "--int-arg"),
        NamedArgument<Converter*>("arg_converter", IntConverter::get_instance())
    );
    parser.add_argument(
        NamedArgument<string>("name", "--int-vec"),
        NamedArgument<Converter*>("arg_converter", IntConverter::get_instance()),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND)
    );

    ArgumentsMap args = parser.parse_args();

    std::cout << "Parsed arguments:" << std::endl;

    for(auto iter = args.begin(); iter != args.end(); ++iter){
        if(iter->first == "--int-arg" || iter->first == "--int-vec")
            continue;

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

    string s;
    std::cout << "Trying to access argument by name (--arg2):" << std::endl;
    args["--arg2"]->get_value(&s);
    std::cout << "Value: " << s << std::endl << std::endl;

    std::cout << "Trying to access optional argument by dest (optional_dest):" << std::endl;
    args["optional_dest"]->get_value(&s);
    std::cout << "Value: " << s << std::endl << std::endl;


    std::cout << "Trying to access positional argument by dest (positional_dest):" << std::endl;
    args["positional_dest"]->get_value(&s);
    std::cout << "Value: " << s << std::endl << std::endl;

    int n;
    std::cout << "Trying to access int optional argument (--int-arg):" << std::endl;
    args["--int-arg"]->get_value(&n);
    std::cout << "Value: " << n << std::endl << std::endl;

    std::vector<int> ns;
    std::cout << "Trying to access int optional append argument (--int-vec):" << std::endl;
    args["--int-vec"]->get_value(&ns);
    std::cout << "Value: " << get_list_as_string(ns) << std::endl << std::endl;
}