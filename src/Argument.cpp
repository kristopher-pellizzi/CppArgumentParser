#include <vector>
#include "Argument.h"

template <typename T>
AP::Argument<T>::Argument(ArgumentDefinition arg_def, T value) : 
    arg_def(arg_def),
    value(value)
{}

template <typename T>
void AP::Argument<T>::get_value(void* container) const{
    *(T*)container = value;
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