#include <iostream>
#include <sstream>
#include "DoubleConverter.h"

using namespace AP;

DoubleConverter* DoubleConverter::instance = NULL;

DoubleConverter::DoubleConverter() {}

DoubleConverter* DoubleConverter::get_instance(){
    if (instance == NULL)
        instance = new DoubleConverter();

    return instance;
}

void DoubleConverter::convert(void* ptr, const string& s){
    try{
        *(double*) ptr = std::stod(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to a double" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void DoubleConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<double> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stod(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a double" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<double>*) ptr = new_vect;
}