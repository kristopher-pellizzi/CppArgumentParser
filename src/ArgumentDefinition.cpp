#include <sstream>
#include <iostream>
#include <vector>
#include "ArgumentDefinition.h"
#include "errors/InvalidArgumentNameException.h"
#include "errors/InvalidAbbreviationException.h"

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

    if (!is_alphanumeric(name[idx]))
        return false;

    while (idx < name.size()){
        if (!is_alphanumeric(name[idx]) && name[idx] != '-')
            return false;
        ++idx;
    }

    return true;
}

bool ArgumentDefinition::is_valid_abbreviation(string abbreviation){
    return abbreviation.size() == 2 && abbreviation[0] == '-' && is_alphanumeric(abbreviation[1]);
}

ArgumentDefinition::ArgumentDefinition(string name, string abbreviation, string help_string, void* default_val, bool required, ArgumentAction action, string dest) :
    name(name),
    abbreviation(abbreviation),
    help_string(help_string),
    default_val(default_val),
    required(required),
    action(action),
    dest(dest)
{

    if (!is_valid_name(name)){
        throw InvalidArgumentNameException(name);
    }

    if (abbreviation != "" && !is_valid_abbreviation(abbreviation)){
        throw InvalidAbbreviationException(abbreviation);
    }

    /*
        If name is a string preceded by a single dash (e.g. -arg1), add a dash so that
        it is coherent with the long optional argument convention (i.e. --arg1)
    */
    if (name.size() > 2 && name[0] == '-' && name[1] != '-'){
        std::stringstream sstream;
        sstream << "-" << name;
        this->name = sstream.str();
    }
}

ArgumentDefinition::ArgumentDefinition(const ArgumentDefinition& other) :
    name(other.name),
    abbreviation(other.abbreviation),
    help_string(other.help_string),
    default_val(NULL),
    required(other.required),
    action(other.action),
    dest(other.dest)
{
    if(other.default_val != NULL){
        if (other.action == ArgumentAction::APPEND){
            std::vector<string>* def_list = (std::vector<string>*) other.default_val;
            default_val = new std::vector<string>(def_list->begin(), def_list->end());
        }
        else
            default_val = new string(* (string*) (other.default_val));
    }
}

ArgumentDefinition& ArgumentDefinition::operator=(const ArgumentDefinition& other){
    name = other.name;
    abbreviation = other.abbreviation;
    help_string = other.help_string;
    default_val = NULL;
    required = other.required;
    action = other.action;
    dest = other.dest;

    if(other.default_val != NULL){
        if (other.action == ArgumentAction::APPEND){
            std::vector<string>* def_list = (std::vector<string>*) other.default_val;
            default_val = new std::vector<string>(def_list->begin(), def_list->end());
        }
        else{
            default_val = new string(* (string*) (other.default_val));
        }
    }
    return *this;
}

ArgumentDefinition::~ArgumentDefinition(){
    if(default_val != NULL){
        if(action == ArgumentAction::APPEND){
            delete (std::vector<string>*) default_val;
        }
        else{
            delete (string*) default_val;
        }
    }
}

string ArgumentDefinition::get_name() const{
    return name;
}

string ArgumentDefinition::get_abbreviation() const{
    return abbreviation;
}

string ArgumentDefinition::get_help_string() const{
    return help_string;
}

void* ArgumentDefinition::get_default_val() const{
    return default_val;
}

bool ArgumentDefinition::is_required() const {
    return required;
}

ArgumentAction ArgumentDefinition::get_action() const {
    return action;
}

string ArgumentDefinition::get_dest() const{
    return dest;
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