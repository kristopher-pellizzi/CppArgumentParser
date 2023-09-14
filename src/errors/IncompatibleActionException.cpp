#include <sstream>
#include "errors/IncompatibleActionException.h"

AP::IncompatibleActionException::IncompatibleActionException(string msg) : msg(msg) 
    {}

const char* AP::IncompatibleActionException::what() const throw(){
    return msg.c_str();
}