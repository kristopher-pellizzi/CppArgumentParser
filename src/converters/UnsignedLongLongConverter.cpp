#include <iostream>
#include <sstream>
#include "UnsignedLongLongConverter.h"

using namespace AP;

UnsignedLongLongConverter* UnsignedLongLongConverter::instance = NULL;

UnsignedLongLongConverter::UnsignedLongLongConverter() {}

UnsignedLongLongConverter* UnsignedLongLongConverter::get_instance(){
    if (instance == NULL)
        instance = new UnsignedLongLongConverter();

    return instance;
}

void UnsignedLongLongConverter::convert(void* ptr, const string& s){
    try{
        *(unsigned long long*) ptr = std::stoull(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an unsigned long long integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void UnsignedLongLongConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<unsigned long long> new_vect;

    for(unsigned long long i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stoull(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an unsigned long long integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<unsigned long long>*) ptr = new_vect;
}