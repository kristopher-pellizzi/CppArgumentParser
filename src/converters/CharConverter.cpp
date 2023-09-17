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

#include <iostream>
#include <sstream>
#include "CharConverter.h"

using namespace AP;

CharConverter* CharConverter::instance = NULL;

CharConverter::CharConverter() {}

CharConverter* CharConverter::get_instance(){
    if (instance == NULL)
        instance = new CharConverter();

    return instance;
}

void CharConverter::convert(void* ptr, const string& s){
    if(s.size() != 1){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an chareger" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }

    *(char*) ptr = s[0];
}

void CharConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<char> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        if (v[i].size() != 1){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an chareger" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }

        new_vect.push_back(v[i][0]);
    }

    *(std::vector<char>*) ptr = new_vect;
}