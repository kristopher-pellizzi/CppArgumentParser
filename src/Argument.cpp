/* *******************************************************************************
 * MIT License
 * 
 * Copyright (c) 2023 Kristopher Francesco Pellizzi
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
******************************************************************************* */

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
void AP::Argument<T>::get_raw_value(void* container) const{
    *(T*)container = value;
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