#include <iostream>
#include <sstream>
#include "LongDoubleConverter.h"

using namespace AP;

LongDoubleConverter* LongDoubleConverter::instance = NULL;

LongDoubleConverter::LongDoubleConverter() {}

LongDoubleConverter* LongDoubleConverter::get_instance(){
    if (instance == NULL)
        instance = new LongDoubleConverter();

    return instance;
}

void LongDoubleConverter::convert(void* ptr, const string& s){
    try{
        *(long double*) ptr = std::stold(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to a long double" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void LongDoubleConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<long double> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stold(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a long double" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<long double>*) ptr = new_vect;
}