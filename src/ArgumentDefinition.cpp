#include <sstream>
#include <iostream>
#include "ArgumentDefinition.h"
#include "errors/InvalidArgumentNameException.h"

using namespace AP;

bool ArgumentDefinition::is_alphanumeric(char c){
    return
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9');
}

bool ArgumentDefinition::is_valid_name(string name){
    unsigned idx = 0;

    while (name[idx] == '-'){
        if (idx++ >= 2)
            return false;
    }

    if (idx == name.size())
        return false;

    while (idx < name.size()){
        if (!is_alphanumeric(name[idx++]))
            return false;
    }

    return true;
}

ArgumentDefinition::ArgumentDefinition(string name, string help_string, string* default_val, bool required) :
    name(name),
    help_string(help_string),
    default_val(default_val),
    required(required)
{

    if (!is_valid_name(name)){
        throw InvalidArgumentNameException(name);
    }

    /*
        If name is a string preceded by a single dash (e.g. -arg1), add a dash so that
        it is coherent with the long optional argument convention (i.e. --arg1)
    */
    if (name.size() > 2 && name[0] == '-' && name[1] != '-'){
        std::stringstream sstream("-");
        sstream << name;
        this->name = sstream.str();
    }
}

ArgumentDefinition::ArgumentDefinition(const ArgumentDefinition& other) :
    name(other.name),
    help_string(other.help_string),
    default_val(NULL),
    required(other.required)
{
    if(other.default_val != NULL)
        default_val = new string(*(other.default_val));
}

ArgumentDefinition& ArgumentDefinition::operator=(const ArgumentDefinition& other){
    name = other.name;
    help_string = other.help_string;
    default_val = NULL;
    required = other.required;

    if(other.default_val != NULL)
        default_val = new string(*(other.default_val));

    return *this;
}

ArgumentDefinition::~ArgumentDefinition(){
    if(default_val != NULL){
        delete default_val;
    }
}

string ArgumentDefinition::get_name() const{
    return name;
}

string ArgumentDefinition::get_help_string() const{
    return help_string;
}

string* ArgumentDefinition::get_default_val() const{
    return default_val;
}

bool ArgumentDefinition::is_required() {
    return required;
}

bool ArgumentDefinition::is_optional() const{
    return name[0] == '-';
}

bool AP::operator<(const ArgumentDefinition& l, const ArgumentDefinition& r){
    return l.name < r.name;
}

bool AP::operator<(const ArgumentDefinition& l, const string& r){
    return l.name < r;
}

bool AP::operator<(const string& l, const ArgumentDefinition& r){
    return l < r.name;
}