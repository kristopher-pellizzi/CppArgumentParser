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
#include <vector>
#include <string>
#include "ArgumentParser.h"

using std::cout;
using std::endl;

using namespace AP;
using std::stringstream;
using std::string;

template <typename T>
string get_list_as_string(std::vector<T>& v){
    if (v.size() == 0)
        return "[]";

    stringstream ss;
    
    ss << "[";
    for(int i = 0; i < v.size() - 1; ++i){
        ss << v[i] << ", ";
    }
    ss << v[v.size() - 1] << "]";

    return ss.str();
}

int main(int argc, char** argv){
    #ifdef DEBUG
    cout << "[*] Creating ArgumentParser..." << endl;    
    #endif
    ArgumentParser parser(argc, argv);
    #ifdef DEBUG
    cout << "[*] ArgumentParser created successfully" << endl;
    #endif

    parser.add_argument(
        NamedArgument<string>("name", "--bool"),
        NamedArgument<Converter*>("arg_converter", BoolConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--char"),
        NamedArgument<Converter*>("arg_converter", CharConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--double"),
        NamedArgument<Converter*>("arg_converter", DoubleConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--float"),
        NamedArgument<Converter*>("arg_converter", FloatConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--int"),
        NamedArgument<Converter*>("arg_converter", IntConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--long"),
        NamedArgument<Converter*>("arg_converter", LongConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--long-double"),
        NamedArgument<Converter*>("arg_converter", LongDoubleConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--long-long"),
        NamedArgument<Converter*>("arg_converter", LongLongConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--path"),
        NamedArgument<Converter*>("arg_converter", PathConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--unsigned"),
        NamedArgument<Converter*>("arg_converter", UnsignedConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--unsigned-long"),
        NamedArgument<Converter*>("arg_converter", UnsignedLongConverter::get_instance())
    );

    parser.add_argument(
        NamedArgument<string>("name", "--unsigned-long-long"),
        NamedArgument<Converter*>("arg_converter", UnsignedLongLongConverter::get_instance())
    );

    ArgumentsMap args = parser.parse_args();

    std::cout << "Parsed arguments:" << std::endl;

    bool b;
    std::cout << "Accessing bool arg" << std::endl;
    args["--bool"]->get_value(&b);
    std::cout << "Value: " << b << std::endl << std::endl;

    char c;
    std::cout << "Accessing char arg" << std::endl;
    args["--char"]->get_value(&c);
    std::cout << "Value: " << c << std::endl << std::endl;

    double d;
    std::cout << "Accessing double arg" << std::endl;
    args["--double"]->get_value(&d);
    std::cout << "Value: " << d + 0.5 << std::endl << std::endl;

    float f;
    std::cout << "Accessing float arg" << std::endl;
    args["--float"]->get_value(&f);
    std::cout << "Value: " << f + 1.1 << std::endl << std::endl;

    int i;
    std::cout << "Accessing int arg" << std::endl;
    args["--int"]->get_value(&i);
    std::cout << "Value: " << i << std::endl << std::endl;

    long l;
    std::cout << "Accessing long arg" << std::endl;
    args["--long"]->get_value(&l);
    std::cout << "Value: " << l << std::endl << std::endl;

    long double ld;
    std::cout << "Accessing long double arg" << std::endl;
    args["--long-double"]->get_value(&ld);
    std::cout << "Value: " << ld << std::endl << std::endl;

    long long ll;
    std::cout << "Accessing long long arg" << std::endl;
    args["--long-long"]->get_value(&ll);
    std::cout << "Value: " << ll << std::endl << std::endl;

    std::filesystem::path p;
    std::cout << "Accessing path arg" << std::endl;
    args["--path"]->get_value(&p);
    std::cout << "Value: " << p << std::endl << std::endl;

    unsigned u;
    std::cout << "Accessing unsigned arg" << std::endl;
    args["--unsigned"]->get_value(&u);
    std::cout << "Value: " << u << std::endl << std::endl;

    unsigned long ul;
    std::cout << "Accessing unsigned long arg" << std::endl;
    args["--unsigned-long"]->get_value(&ul);
    std::cout << "Value: " << ul << std::endl << std::endl;

    unsigned long long ull;
    std::cout << "Accessing unsigned long long arg" << std::endl;
    args["--unsigned-long-long"]->get_value(&ull);
    std::cout << "Value: " << ull << std::endl << std::endl;

}