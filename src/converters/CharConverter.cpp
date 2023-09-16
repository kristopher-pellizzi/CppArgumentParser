#include <iostream>
#include <sstream>
#include "CharConverter.h"

using namespace AP;

CharConverter* CharConverter::instance = NULL;

CharConverter::CharConverter() {}

CharConverter* CharConverter::get_instance(){
    if (instance == NULL)
        instance = new CharConverter();

    return instance;
}

void CharConverter::convert(void* ptr, const string& s){
    if(s.size() != 1){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an chareger" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }

    *(char*) ptr = s[0];
}

void CharConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<char> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        if (v[i].size() != 1){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an chareger" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }

        new_vect.push_back(v[i][0]);
    }

    *(std::vector<char>*) ptr = new_vect;
}