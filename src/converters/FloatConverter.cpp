#include <iostream>
#include <sstream>
#include "FloatConverter.h"

using namespace AP;

FloatConverter* FloatConverter::instance = NULL;

FloatConverter::FloatConverter() {}

FloatConverter* FloatConverter::get_instance(){
    if (instance == NULL)
        instance = new FloatConverter();

    return instance;
}

void FloatConverter::convert(void* ptr, const string& s){
    try{
        *(float*) ptr = std::stof(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to a float" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void FloatConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<float> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stof(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a float" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<float>*) ptr = new_vect;
}