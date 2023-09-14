#include "ArgumentAction.h"

std::ostream& operator<<(std::ostream& out, const AP::ArgumentAction& action){
   switch (action){
        case AP::ArgumentAction::STORE:
            return out << "STORE";
        case AP::ArgumentAction::STORE_FALSE:
            return out << "STORE_FALSE";
        case AP::ArgumentAction::STORE_TRUE:
            return out << "STORE_TRUE";
        case AP::ArgumentAction::APPEND:
            return out << "APPEND";
        default:
            return out << "Unknown Action";
   } 
}