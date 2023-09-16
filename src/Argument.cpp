#include <vector>
#include "Argument.h"

template <typename T>
AP::Argument<T>::Argument(ArgumentDefinition arg_def, T value) : 
    arg_def(arg_def),
    value(value)
{}

template <typename T>
void AP::Argument<T>::convert_value(void* container) const {
    if (is_multivalue()){
        (arg_def.get_converter())->convert(container, value);
    }
    else
        (arg_def.get_converter())->convert(container, value);
}

template <typename T>
void AP::Argument<T>::get_value(void* container) const{
    Converter* arg_converter = arg_def.get_converter();
    if(arg_converter != NULL)
        convert_value(container); 
    else{
        *(T*)container = value;
    }
}

template <typename T>
string AP::Argument<T>::get_name() const{
    return arg_def.get_name();
}

template <typename T>
bool AP::Argument<T>::is_multivalue() const{
    return arg_def.get_action() == ArgumentAction::APPEND;
}

template <typename T>
AP::ArgumentAction AP::Argument<T>::get_action() const{
    return arg_def.get_action(); 
}

template class AP::Argument<string>;
template class AP::Argument<std::vector<string>>;