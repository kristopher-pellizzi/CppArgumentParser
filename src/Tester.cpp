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

    parser.add_argument("arg1");
    parser.add_argument("--arg2");
    parser.add_argument("--Arg4");
    parser.add_argument("-arg3");
    parser.add_argument("arg6");

    ArgumentsMap args = parser.parse_args();

    std::cout << "Parsed arguments:" << std::endl;

    for(auto iter = args.begin(); iter != args.end(); ++iter){
        std::cout << "Name: " << iter->first << "; Value: " << (iter->second).get_value() << std::endl;
    }

    std::cout << "Trying to access argument by name (--arg2):" << std::endl;
    std::cout << "Value: " << args["--arg2"].get_value() << std::endl;
}