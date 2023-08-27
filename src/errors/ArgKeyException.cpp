#include <sstream>
#include "errors/ArgKeyException.h"

AP::ArgKeyException::ArgKeyException(string key) : 
    key(key) 
{}

const char* AP::ArgKeyException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Argument " << key << " not found in arguments map" << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}