#include "Argument.h"

AP::Argument::Argument(const ArgumentDefinition& arg_def, string value) : 
    arg_def(arg_def),
    value(value)
{}

string AP::Argument::get_value() const{
    return value;
}

string AP::Argument::get_name() const{
    return arg_def.get_name();
}