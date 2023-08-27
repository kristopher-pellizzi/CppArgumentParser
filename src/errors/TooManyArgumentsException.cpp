#include <sstream>
#include "errors/TooManyArgumentsException.h"

AP::TooManyArgumentsException::TooManyArgumentsException(unsigned expected, unsigned given) : 
    expected(expected),
    given(given) 
{}

const char* AP::TooManyArgumentsException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Too many positional arguments detected. Expected " << expected << "; given " << given << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}