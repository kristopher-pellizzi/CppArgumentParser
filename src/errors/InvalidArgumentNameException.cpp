#include <sstream>
#include "errors/InvalidArgumentNameException.h"

AP::InvalidArgumentNameException::InvalidArgumentNameException(string arg_name) : arg_name(arg_name) {}

const char* AP::InvalidArgumentNameException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Invalid argument name '" << arg_name << "'." << std::endl;
    sstream << "Argument names must only contain alphanumeric characters." << std::endl;
    sstream << "Optional arguments must begin with '-' character" << std::endl;
    sstream << "Arguments can contain at most a double dash at the beginning" << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}