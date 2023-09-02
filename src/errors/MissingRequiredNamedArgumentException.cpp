#include <sstream>
#include "errors/MissingRequiredNamedArgumentException.h"

NA::MissingRequiredNamedArgumentException::MissingRequiredNamedArgumentException(string arg_name) : arg_name(arg_name) {}

const char* NA::MissingRequiredNamedArgumentException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Function call is missing required named argument '" << arg_name << "'." << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}