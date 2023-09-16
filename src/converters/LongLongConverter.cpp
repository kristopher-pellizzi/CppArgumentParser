#include <iostream>
#include <sstream>
#include "LongLongConverter.h"

using namespace AP;

LongLongConverter* LongLongConverter::instance = NULL;

LongLongConverter::LongLongConverter() {}

LongLongConverter* LongLongConverter::get_instance(){
    if (instance == NULL)
        instance = new LongLongConverter();

    return instance;
}

void LongLongConverter::convert(void* ptr, const string& s){
    try{
        *(long long*) ptr = std::stoll(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void LongLongConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<long long> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stoll(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a long long integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<long long>*) ptr = new_vect;
}