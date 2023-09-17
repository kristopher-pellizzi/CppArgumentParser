#include <iostream>
#include <sstream>
#include "BoolConverter.h"

using namespace AP;

BoolConverter* BoolConverter::instance = NULL;

BoolConverter::BoolConverter() {}

BoolConverter* BoolConverter::get_instance(){
    if (instance == NULL)
        instance = new BoolConverter();

    return instance;
}

void BoolConverter::convert(void* ptr, const string& s){
    if (s == "true")
        * (bool*) ptr = true;
    else if (s == "false")
        * (bool*) ptr = false;
    else { 
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to a boolean" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void BoolConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<bool> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        if (v[i] == "true")
            new_vect.push_back(true);
        else if (v[i] == "false")
            new_vect.push_back(false);
        else{
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a boolean" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<bool>*) ptr = new_vect;
}