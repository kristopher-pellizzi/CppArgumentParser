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

#include <sstream>
#include <filesystem>
#include "UsageManualGenerator.h"

using namespace AP;

string UsageManualGenerator::tab = "    "; // 4 spaces

string UsageManualGenerator::get_list_as_string(const std::vector<string>& v){
    if (v.size() == 0)
        return "[]";

    std::stringstream ss;
    
    ss << "[";
    for(int i = 0; i < v.size() - 1; ++i){
        ss << v[i] << ", ";
    }
    ss << v[v.size() - 1] << "]";

    return ss.str();
}

string UsageManualGenerator::get_default_val(const ArgumentDefinition& def, void* default_val){
    if (def.get_action() == ArgumentAction::APPEND){
        return get_list_as_string(* (std::vector<string>*) default_val);
    }

    return * (string*) default_val;
}

string UsageManualGenerator::get_fixed_length_lines(const string& help_string, unsigned len){
    if (help_string.size() == 0)
        return "";

    size_t added_chars = 0;
    std::stringstream sstream;
    while(added_chars < help_string.size()){
        string current_block = help_string.substr(added_chars, len - 1);
        sstream << current_block;
        added_chars += (len - 1);
        added_chars = std::min(added_chars, help_string.size());
        /*
            If the len-th character of the current block is not a space, we are
            truncating a word, so add "-" and go to a new line
        */
        if (! std::isspace(help_string[added_chars]) && help_string[added_chars] != '\0')
            sstream << "-" << std::endl << tab;
        else{
        /*
            Otherwise, there's no need to add "-" as we are not truncating any word,
            keep going normally, increasing the added_chars counter to count the added space
        */
            sstream << help_string[added_chars] << std::endl;
            if (help_string[added_chars++] != '\0')
                sstream << tab;
        }
    }

    return sstream.str();
}

string UsageManualGenerator::generate_help_string(const ArgumentDefinition& def){
    const string& name = def.get_name();
    const string& abbreviation = def.get_abbreviation();
    const string& help_string = def.get_help_string();
    void* default_value = def.get_default_val();

    std::stringstream sstream;
    sstream << name;

    if (abbreviation != "")
        sstream << ", " << abbreviation; 

    sstream << std::endl;

    if (help_string.size() > 0)
        sstream << tab << get_fixed_length_lines(help_string);
    
    if (default_value != NULL){
        sstream << tab << "Default: " << get_default_val(def, default_value) << std::endl;
    }

    if (def.is_optional() && def.is_required()){
        sstream << tab << "[Required]" << std::endl;
    }

    sstream << std::endl;

    return sstream.str();
}

string UsageManualGenerator::generate_usage_manual(
    const string& program_path,
    const std::vector<ArgumentDefinition>& positional_arg_defs,
    const std::set<ArgumentDefinition, std::less<>>& optional_arg_defs
){
    std::stringstream sstream;
    std::stringstream usage_sstream;
    string program_name = std::filesystem::path(program_path).filename().string();

    usage_sstream << "Usage: " << std::endl;
    usage_sstream << program_name << " ";

    if (positional_arg_defs.size() > 0){
        sstream << "[*] Positional Args:" << std::endl;
        for(unsigned i = 0; i < positional_arg_defs.size(); ++i){
            usage_sstream << positional_arg_defs[i].get_name() << " ";
            sstream << generate_help_string(positional_arg_defs[i]) << std::endl;
        }
    }

    if (optional_arg_defs.size() > 0){
        sstream << "[*] Optional Args: " << std::endl;
        for(auto iter = optional_arg_defs.begin(); iter != optional_arg_defs.end(); ++iter){
            usage_sstream << "[" << iter->get_name() << "]";
            if (iter->get_action() == ArgumentAction::APPEND)
                usage_sstream << "... ";
            else
                usage_sstream << " ";

            sstream << generate_help_string(*iter) << std::endl;
        }
    }

    usage_sstream << std::endl << std::endl << sstream.str();

    return usage_sstream.str();
}