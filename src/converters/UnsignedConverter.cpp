#include <iostream>
#include <sstream>
#include <limits.h>
#include "UnsignedConverter.h"

using namespace AP;

UnsignedConverter* UnsignedConverter::instance = NULL;

UnsignedConverter::UnsignedConverter() {}

UnsignedConverter* UnsignedConverter::get_instance(){
    if (instance == NULL)
        instance = new UnsignedConverter();

    return instance;
}

void UnsignedConverter::convert(void* ptr, const string& s){
    unsigned long n;

    try{
        n = std::stoul(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an unsigned integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }

    if (n <= UINT_MAX)
        * (unsigned*) ptr = n;
    else{ 
        std::stringstream sstream;
        sstream << "Value " << s << " is out of range for an unsigned integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }

}

void UnsignedConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<unsigned> new_vect;
    unsigned long n;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            n = std::stoul(v[i]);
            new_vect.push_back(std::stoul(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an unsigned integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }

        if (n <= UINT_MAX)
            new_vect.push_back(n);
        else{
            std::stringstream sstream;
            sstream << "Value " << v[i] << " is out of range for an unsigned integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<unsigned>*) ptr = new_vect;
}