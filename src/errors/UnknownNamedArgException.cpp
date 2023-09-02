#include <sstream>
#include "errors/UnknownNamedArgException.h"

NA::UnknownNamedArgumentException::UnknownNamedArgumentException(string arg_name) : arg_name(arg_name) {}

const char* NA::UnknownNamedArgumentException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Unknown named argument '" << arg_name << "'." << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}