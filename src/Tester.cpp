#include <iostream>
#include "ArgumentParser.h"

using std::cout;
using std::endl;

using namespace AP;

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

    ArgumentsMap args = parser.parse_args();

    std::cout << "Parsed arguments:" << std::endl;

    for(auto iter = args.begin(); iter != args.end(); ++iter){
        std::cout << "Name: " << iter->first << "; Value: " << (iter->second).get_value() << std::endl;
    }

    std::cout << "Trying to access argument by name (--arg2):" << std::endl;
    std::cout << "Value: " << args["--arg2"].get_value() << std::endl;
}