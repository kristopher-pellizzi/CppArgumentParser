#include <iostream>
#include <sstream>
#include "LongConverter.h"

using namespace AP;

LongConverter* LongConverter::instance = NULL;

LongConverter::LongConverter() {}

LongConverter* LongConverter::get_instance(){
    if (instance == NULL)
        instance = new LongConverter();

    return instance;
}

void LongConverter::convert(void* ptr, const string& s){
    try{
        *(long*) ptr = std::stol(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void LongConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<long> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stol(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a long integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<long>*) ptr = new_vect;
}