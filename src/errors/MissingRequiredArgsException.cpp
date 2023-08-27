#include <sstream>
#include "errors/MissingRequiredArgsException.h"

AP::MissingRequiredArgsException::MissingRequiredArgsException(std::set<string>& missing_args) : missing_args(missing_args) {}

const char* AP::MissingRequiredArgsException::what() const throw(){
    std::stringstream sstream;

    sstream << std::endl;
    for (auto iter = missing_args.begin(); iter != missing_args.end(); ++iter){
        sstream << "Missing required argument " << *iter << std::endl;
    }

    string* ret = new string(sstream.str());

    return ret->c_str();
}