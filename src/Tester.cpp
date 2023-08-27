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

    parser.parse_args();
}