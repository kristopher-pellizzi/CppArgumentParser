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
#include <limits.h>
#include "UnsignedConverter.h"

using namespace AP;

UnsignedConverter* UnsignedConverter::instance = NULL;

UnsignedConverter::UnsignedConverter() {}

UnsignedConverter* UnsignedConverter::get_instance(){
    if (instance == NULL)
        instance = new UnsignedConverter();

    return instance;
}

void UnsignedConverter::convert(void* ptr, const string& s){
    unsigned long n;

    try{
        n = std::stoul(s);
    } 
    catch (std::exception& e){
        std::stringstream sstream;
        sstream << "Cannot convert value " << s << " to an unsigned integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }

    if (n <= UINT_MAX)
        * (unsigned*) ptr = n;
    else{ 
        std::stringstream sstream;
        sstream << "Value " << s << " is out of range for an unsigned integer" << std::endl;
        throw ArgumentConversionException(sstream.str(), s);
    }

}

void UnsignedConverter::convert(void* ptr, const std::vector<string>& v){
    std::vector<unsigned> new_vect;
    unsigned long n;

    for(unsigned i = 0; i < v.size(); ++i){
        try{
            n = std::stoul(v[i]);
            new_vect.push_back(std::stoul(v[i]));
        } 
        catch (std::exception& e){
            std::stringstream sstream;
            sstream << "Cannot convert value " << v[i] << " to an unsigned integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }

        if (n <= UINT_MAX)
            new_vect.push_back(n);
        else{
            std::stringstream sstream;
            sstream << "Value " << v[i] << " is out of range for an unsigned integer" << std::endl;
            throw ArgumentConversionException(sstream.str(), v[i]);
        }
    }

    *(std::vector<unsigned>*) ptr = new_vect;
}