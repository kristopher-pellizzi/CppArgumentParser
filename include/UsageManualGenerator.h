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

#ifndef USAGEMANUALGENERATOR
#define USAGEMANUALGENERATOR

#include <string>
#include <set>
#include <vector>
#include "ArgumentDefinition.h"

using std::string;

namespace AP{
    class UsageManualGenerator{
        private:
            static string tab;

            static string get_list_as_string(const std::vector<string>& v);
            static string get_default_val(const ArgumentDefinition& def, void* default_val);
            static string get_fixed_length_lines(const string& help_string, unsigned len = 60);
            static string generate_help_string(const ArgumentDefinition& def);

        public:
            UsageManualGenerator() = delete;
            UsageManualGenerator(const UsageManualGenerator& other) = delete;
            UsageManualGenerator& operator=(const UsageManualGenerator& other) = delete;

            static string generate_usage_manual(
                const string& program_path,
                const std::vector<ArgumentDefinition>& positional_arg_defs,
                const std::set<ArgumentDefinition, std::less<>>& optional_arg_defs
            );
    };
}

#endif // USAGEMANUALGENERATOR