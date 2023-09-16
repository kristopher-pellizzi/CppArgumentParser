#include <iostream>
#include <sstream>
#include "UnsignedLongConverter.h"

using namespace AP;

UnsignedLongConverter* UnsignedLongConverter::instance = NULL;

UnsignedLongConverter::UnsignedLongConverter() {}

UnsignedLongConverter* UnsignedLongConverter::get_instance(){
    if (instance == NULL)
        instance = new UnsignedLongConverter();

    return instance;
}

void UnsignedLongConverter::convert(void* ptr, const string& s){
    try{
        *(unsigned long*) ptr = std::stoul(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an unsigned long integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void UnsignedLongConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<unsigned long> new_vect;

    for(unsigned long i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stoul(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an unsigned long integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<unsigned long>*) ptr = new_vect;
}