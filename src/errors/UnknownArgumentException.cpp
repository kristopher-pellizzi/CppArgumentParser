#include <sstream>
#include "errors/UnknownArgumentException.h"

AP::UnknownArgumentException::UnknownArgumentException(string arg_name) : arg_name(arg_name) {}

const char* AP::UnknownArgumentException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Unknown argument '" << arg_name << "' detected." << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}