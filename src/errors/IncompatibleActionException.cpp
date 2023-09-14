#include <sstream>
#include "errors/IncompatibleActionException.h"

AP::IncompatibleActionException::IncompatibleActionException(ArgumentAction given) {
    switch (given){
        case ArgumentAction::STORE:
            this->given = "STORE";
            break;
        case ArgumentAction::STORE_TRUE:
            this->given = "STORE_TRUE";
            break;
        case ArgumentAction::STORE_FALSE:
            this->given = "STORE_FALSE";
            break;
        case ArgumentAction::APPEND:
            this->given = "APPEND";
            break;
    }
}

const char* AP::IncompatibleActionException::what() const throw(){
    std::stringstream sstream;
    sstream << std::endl << "Given action '" << given << "' can only be used with optional arguments" << std::endl;

    string* ret = new string(sstream.str());

    return ret->c_str();
}