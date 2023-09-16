#include <iostream>
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
    *(int*) ptr = std::stoi(s);
}

void IntConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<int> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        new_vect.push_back(std::stoi(v[i]));
    }

    *(std::vector<int>*) ptr = new_vect;
}