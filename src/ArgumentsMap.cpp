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

#include "ArgumentsMap.h"
#include "errors/ArgKeyException.h"

AP::ArgumentsMap::ArgumentsMap(const std::map<string, IArgument*>& init){
    args = std::map<string, IArgument*>();

    for (auto iter = init.cbegin(); iter != init.cend(); ++iter){
        args.insert(std::pair<string, IArgument*>(iter->first, iter->second->clone()));
    }
}

AP::ArgumentsMap::ArgumentsMap(const ArgumentsMap& other){
    args = std::map<string, IArgument*>();

    for (auto iter = other.args.cbegin(); iter != other.args.cend(); ++iter){
        args.insert(std::pair<string, IArgument*>(iter->first, iter->second->clone()));
    }
}

AP::ArgumentsMap& AP::ArgumentsMap::operator=(const ArgumentsMap& other){
    this->args = std::map<string, IArgument*>();

    for (auto iter = other.args.cbegin(); iter != other.args.cend(); ++iter){
        args.insert(std::pair<string, IArgument*>(iter->first, iter->second->clone()));
    }

    return *this;
}

AP::IArgument* AP::ArgumentsMap::operator[](const string& key){
    auto found = args.find(key);

    if (found != args.end())
        return found->second;

    throw ArgKeyException(key);
}

std::map<string, AP::IArgument*>::iterator AP::ArgumentsMap::begin(){
    return args.begin();
}

std::map<string, AP::IArgument*>::iterator AP::ArgumentsMap::end(){
    return args.end();
}