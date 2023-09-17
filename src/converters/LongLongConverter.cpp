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
#include "LongLongConverter.h"

using namespace AP;

LongLongConverter* LongLongConverter::instance = NULL;

LongLongConverter::LongLongConverter() {}

LongLongConverter* LongLongConverter::get_instance(){
    if (instance == NULL)
        instance = new LongLongConverter();

    return instance;
}

void LongLongConverter::convert(void* ptr, const string& s){
    try{
        *(long long*) ptr = std::stoll(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void LongLongConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<long long> new_vect;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stoll(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to a long long integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<long long>*) ptr = new_vect;
}