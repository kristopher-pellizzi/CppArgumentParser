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

#ifndef ARGUMENTDEF
#define ARGUMENTDEF

#include <string>
#include "ArgumentAction.h"
#include "Converter.h"

using std::string;

namespace AP{
    class ArgumentDefinition{
        private:
            string name;
            string abbreviation;
            string help_string;
            void* default_val;
            bool required;
            ArgumentAction action;
            string dest;
            Converter* arg_converter;

            static bool is_alphanumeric(char c);
            static bool is_valid_name(string name);
            static bool is_valid_abbreviation(string abbreviation);

        public:
            ArgumentDefinition(string name, string abbreviation, string help_string, void* default_val, bool required, ArgumentAction action, string dest, Converter* arg_converter);
            ArgumentDefinition(const ArgumentDefinition& other);
            ArgumentDefinition& operator=(const ArgumentDefinition& other);
            ~ArgumentDefinition();

            string get_name() const;
            string get_abbreviation() const;
            string get_help_string() const;
            void* get_default_val() const;
            bool is_required() const;
            bool is_optional() const;
            ArgumentAction get_action() const;
            string get_dest() const;
            Converter* get_converter() const;

            friend bool operator<(const ArgumentDefinition& l, const ArgumentDefinition& r);
            friend bool operator<(const ArgumentDefinition& l, const string& r);
            friend bool operator<(const string& l, const ArgumentDefinition& r);
    };
}

#endif // ARGUMENTDEF