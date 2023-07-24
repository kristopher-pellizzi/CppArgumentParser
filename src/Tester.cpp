#include <iostream>
#include "ArgumentParser.h"

using std::cout;
using std::endl;

using namespace AP;

int main(int argc, char** argv){
    cout << "Creating ArgumentParser..." << endl;    
    ArgumentParser parser(argc, argv);
    cout << "ArgumentParser created successfully" << endl;

    parser.add_argument("arg1");
    parser.add_argument("--arg2");
    parser.add_argument("--Arg4");
    parser.add_argument("-arg3");
    parser.add_argument("arg6");
}