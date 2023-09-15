#include <sstream>
#include "errors/InvalidAbbreviationException.h"

AP::InvalidAbbreviationException::InvalidAbbreviationException(string abbreviation) : abbreviation(abbreviation) {}

const char* AP::InvalidAbbreviationException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Invalid argument abbreviation '" << abbreviation << "'." << std::endl;
    sstream << "Argument abbreviations must begin with a dash (-) character, followed by a single alphanumeric character." << std::endl;
    sstream << "Example: -t" << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}