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

#include "NamedArgumentsParser.h"
#include "errors/UnknownNamedArgException.h"
#include "errors/MissingRequiredNamedArgumentException.h"

using namespace NA;

void NamedArgumentsParser::check_args(){
    for(auto iter = args.begin(); iter != args.end(); ++iter){
        auto found = sig.signature.find(iter->first);

        if (found == sig.signature.end())
            throw UnknownNamedArgumentException(iter->first);
    }

    for(auto iter = sig.signature.begin(); iter != sig.signature.end(); ++iter){
        IArgumentProperties* arg_props = iter->second;
        if (arg_props->is_required()){
            auto found = args.find(iter->first);

            if (found == args.end())
                throw MissingRequiredNamedArgumentException(iter->first);
        }
    }
}

NamedArgumentsParser::NamedArgumentsParser(FunctionSignature& sig, std::map<string, void*>& args) :
    sig(sig),
    args(args)
{
    check_args();
}