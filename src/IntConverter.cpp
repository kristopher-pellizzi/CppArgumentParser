#include <iostream>
#include <sstream>
#include "IntConverter.h"

using namespace AP;

IntConverter* IntConverter::instance = NULL;

IntConverter::IntConverter() {}

IntConverter* IntConverter::get_instance(){
    if (instance == NULL)
        instance = new IntConverter();

    return instance;
}

void IntConverter::convert(void* ptr, const string& s){
    try{
        *(int*) ptr = std::stoi(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void IntConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<int> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stoi(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<int>*) ptr = new_vect;
}