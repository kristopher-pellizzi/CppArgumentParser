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

#ifndef NAMEDARG
#define NAMEDARG

#include <string>
#include <iostream>

using std::string;

namespace NA{
    template <typename T>
    class NamedArgument{
        private:
            string name;
            T* value;

        public:
            NamedArgument<T>(string name, T value) : name(name), value(new T(value)){}
            NamedArgument<T>(const NamedArgument<T>& other) : name(other.name), value(new T(*other.value)){}
            NamedArgument<T>& operator=(const NamedArgument<T>& other){
                name = other.name;
                value = new T(*other.value);

                return *this;
            }

            ~NamedArgument<T>(){
                delete value;
            }

            const string& getName() const{
                return name;
            }

            const T* getValue() const{
                return value;
            }

            bool operator==(const NamedArgument<T>& other){
                name == other.name;
            }
    };

    NamedArgument<void*> ENDL("__NA::endl__", NULL);

}


#endif // NAMEDARG