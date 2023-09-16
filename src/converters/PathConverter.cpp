#include <iostream>
#include <sstream>
#include "PathConverter.h"

using namespace AP;

PathConverter* PathConverter::instance = NULL;

PathConverter::PathConverter() {}

PathConverter* PathConverter::get_instance(){
    if (instance == NULL)
        instance = new PathConverter();

    return instance;
}

void PathConverter::convert(void* ptr, const string& s){
    try{
        *(std::filesystem::path*) ptr = std::filesystem::path(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an instance of std::filesystem::path" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void PathConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<std::filesystem::path> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::filesystem::path(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an instance of std::filesystem::path" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<std::filesystem::path>*) ptr = new_vect;
}