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
#include "UnsignedLongConverter.h"

using namespace AP;

UnsignedLongConverter* UnsignedLongConverter::instance = NULL;

UnsignedLongConverter::UnsignedLongConverter() {}

UnsignedLongConverter* UnsignedLongConverter::get_instance(){
    if (instance == NULL)
        instance = new UnsignedLongConverter();

    return instance;
}

void UnsignedLongConverter::convert(void* ptr, const string& s){
    try{
        *(unsigned long*) ptr = std::stoul(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an unsigned long integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }
}

void UnsignedLongConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<unsigned long> new_vect;

    for(unsigned long i = 0; i < v.size(); ++i){
        try{
            new_vect.push_back(std::stoul(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an unsigned long integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<unsigned long>*) ptr = new_vect;
}