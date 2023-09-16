#include <sstream>
#include "errors/ArgumentConversionException.h"

AP::ArgumentConversionException::ArgumentConversionException(string msg, string arg) : msg(msg), arg(arg) {}

const char* AP::ArgumentConversionException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Error during conversion of value " << arg << std::endl;
    sstream << msg << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}