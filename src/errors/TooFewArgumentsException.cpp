#include <sstream>
#include "errors/TooFewArgumentsException.h"

AP::TooFewArgumentsException::TooFewArgumentsException(unsigned expected, unsigned given) : 
    expected(expected),
    given(given) 
{}

const char* AP::TooFewArgumentsException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Too few positional arguments detected. Expected " << expected << "; given " << given << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}