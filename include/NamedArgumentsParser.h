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

#ifndef NAMED_ARGS_PARSER
#define NAMED_ARGS_PARSER

#include <map>
#include <string>
#include "FunctionSignature.h"

using std::string;

namespace NA{
    class NamedArgumentsParser{
        private:
            FunctionSignature& sig;
            std::map<string, void*>& args;

            void check_args();

        public:
            NamedArgumentsParser(FunctionSignature& sig, std::map<string, void*>& args);

            template <typename T>
            void get(T* var, string k){
                auto args_found = args.find(k);

                if (args_found != args.end()){
                    *var = *(T*) args_found->second;
                    return;
                }

                auto sig_found = sig.signature.find(k);
                *var = *(T*) (sig_found->second)->get_default_val();
                return;
            }
    };
}

#endif // NAMED_ARGS_PARSER