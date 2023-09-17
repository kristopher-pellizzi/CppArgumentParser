# C++ Argument Parser

Implementation of a command-line argument parser for C++ inspired to **Python** library [argparse](https://docs.python.org/3/library/argparse.html).
The library allows to easily **specify which arguments a program accepts** and parses all the arguments provided as input, making the given values available in an easy-to-access **map** structure.
The library also builds a **usage manual** according to the arguments specified for the program, and automatically defines a **--help, -h** argument that allows a user to print the usage manual as a documentation.

## Build
A `makefile` is available in the root of the repository.
If you have the *make* utility installed, simply execute the command `make` from the root, or `make -f /path/to/makefile` from any folder to launch the building process.
When the command execution ends, the library will be available in the following path relative to the repository root: `lib/libArgumentParser.so`.
**NOTE: the building process may take a while.**

## Usage
The provided `makefile` builds the library so that it can be dynamically linked into any C++ program.
In order to use the library in a program, you must:
-   Add the `lib` folder to the library search path by using argument `-L/path/to/lib`
-   Specify the name of the library with argument `-lArgumentParser`
-   Include header file `ArgumentParser.h`

*Example compilation command*:
``` bash
g++ -L/home/user/CppArgumentParser/lib -lArgumentParser example_program.cpp
```

## Documentation
### Basics
The main component of the library is a class named `ArgumentParser`, whose constructor simply takes as arguments main function's arguments `argc` and `argv`.
When an instance of `ArgumentParser` is created, you can simply call member function `add_argument` to specify a new argument accepted by the program.
`ArgumentParser` allows to specify both **positional** and **optional** parameters.
Member function `add_argument` accepts a **variadic** list of arguments.
In order to provide **flexibility** to this function call, a *Named Argument System* has been built into the library, so that the function accepts a list of arguments of type `NamedArgument`.
This way, it is possible to specify a new argument by calling `add_argument` and passing it the list of parameters **in any order**, also **avoiding to explicitly specify the optional parameters**.
After having specified the list of arguments accepted by the program, a call to member function `parse_args` will return an instance of class `ArgumentsMap`, which is a dict-like object that allows to easily access the parsed arguments by name.
The `ArgumentsMap` associates the name (or **dest**, see `add_argument` [signature](#add_argument) below) of an argument, to an instance of class `Argument`, that exposes a member function `get_value` to retrieve the value parsed from command-line and stored into it.

### ArgumentParser
#### Constructor
``` c++
ArgumentParser(int argc, char** argv)
```
##### Parameters
**argc**: number of arguments passed to the `main` function
**argv**: array containing the list of arguments passed to the `main` function

#### Methods
##### add_argument
``` c++
void add_argument(NamedArgument<T> arg...)
```
###### Parameters
**arg...**: variadic list of arguments for the function. See `NamedArgument` [signature](#namedargument) below for more information. The following arguments are accepted by the function:
-   **name** (string) - *Required*: specifies the name of the argument that will be accepted by the program. Strings that start with "--" define an optional argument, otherwise a positional argument is defined.
-   **abbreviation** (string) - *Optional*: specifies the abbreviation that can be used instead of the name (for optional program arguments only)
-   **help_string** (string) - *Optional*: string that explaines the user what an argument is and why it is useful. The given string is printed to stdout in the usage manual.
-   **default_val** (string\*) - *Optional*: specifies a default value for an argument in case it is not explicitly provided by the user. 
**NOTE: the given pointer is automatically deleted by the `ArgumentParser`**.
-   **is_required** (bool) - *Optional*: specifies whether an optional argument is actually required (the program stops if it is not provided by the user). **false** by default.
-   **action** (ArgumentAction) - *Optional*: specifies the action that the parser must take whenever it parses the argment. **ArgumentAction::STORE** by default. See `ArgumentAction` [signature](#argumentaction) below for more information.
-   **dest** (string) - *Optional*: specifies the string that will be used as a key in the `ArgumentsMap`. If not provided, the name of the argumet is used by default.
-   **arg_converter** (Converter\*) - *Optional*: by default, arguments are all considered strings. If needed, the arg_converter can be used in order to automatically convert the parsed value into another specific type (e.g. int) when retrieved from the `ArgumentsMap`.

##### parse_args
``` c++
ArgumentsMap parse_args()
```

##### print_usage_manual
``` c++
void print_usage_manual()
```

### NamedArgument
#### Constructor
``` c++
NamedArgument<T>(string name, T value)
```

### ArgumentAction
#### Values
- **ArgumentAction::STORE**: the parser simply stores the parsed value into a variable. Passing the same argument multiple times will overwrite the argument value.
- **ArgumentAction::STORE_TRUE**: the parser simply verifies the presence of the argument. If it is passed by the user to the program, its value will be `true`, otherwise `false`.
- **ArgumentAction::STORE_FALSE**: the parser simply verifies the presence of the argument. If it is passed by the user to the program, its value will be `false`, otherwise `true`.
- **ArgumentAction::APPEND**: the parser will store all the values parsed for the given argument, appending them to a list. This way, the user can pass the same argument multiple times, thus specifying a multi-valued argument.

### ArgumentsMap
#### Constructor
The constructor is used by an instance of `ArgumentParser` to provide  an easy-to-access dict-like object to retrieve the parsed arguments.
``` c++
ArgumentsMap(const std::map<string, IArgument\*>& init)
```

##### Parameters
**init**: map that associates a string to a pointer to an instance of `Argument`

#### Methods
##### operator[]
``` c++
IArgument* operator[](const string& key)
```
Allows to access the `ArgumentsMap` as a dictionary, returning the instance of `Argument` associated with the given key.
###### Parameters
**key**: name or dest of the argument whose value is requested

##### begin
``` c++
std::map<string, IArgument\*>::iterator begin()
```
Returns an iterator that points to the first element of the `ArgumentsMap`

##### end
``` c++
std::map<string, IArgument\*>::iterator end()
```
Return an iterator that points to past the last element of the `ArgumentsMap`

### Argument
#### Constructor
``` c++
Argument(ArgumentDefinition arg_def, T value)
```
The constructor is used by the `ArgumentParser` to add elements to the `ArgumentsMap`.

##### Parameters
**arg_def**: definition of the argument to be parsed. It is a wrapper object that contains all the information passed to function `add_argument`.
**value**: value parsed for the given argument. It can be a single string or a vector of strings (for arguments with action **ArgumentAction::APPEND**)

#### Methods
##### get_name
``` c++
string get_name()
```
Returns the name of the argument

##### is_multivalue
``` c++
bool is_multivalue()
```
Returns true if the action associated to the argument is ArgumentAction::APPEND, false otherwise

##### get_action
``` c++
ArgumentAction get_action()
```
Returns the action associated to the argument

##### get_value
``` c++
void get_value(void* container)
```
Stores the value associated to the argument into the memory cell pointed to by `container`.
**NOTE: container must be a pointer of the correct type, i.e. string or vector\<string> (if action is APPEND) if no converter is provided; T or vector\<T>(is action is APPEND) if a converter is provided that converts the argument value to type T.**

## Converters
In order to automatically convert values parsed by `ArgumentParser`, it is possible to define a converter class that inherits from the abstract class `Converter`.
This interface exposes the 2 versions of method `convert` described below.

### Methods
#### convert (string)
``` c++
void convert(void* ptr, const string& s)
```
Converts string `s` and stores the converted value into `ptr`.
`ptr` **MUST** be a pointer of the correct type (e.g. int for IntConverter).

#### convert (vector<string>)
``` c++
void convert(void* ptr, const std::vector<string>& v)
```
Converts vector `v` to a vector of the target type and stores the converted vector into `ptr`.
`ptr` **MUST** be a pointer of the correct type (e.g. vector\<int> for IntConverter).

### Extensibility and OOTB Converters
It is possible to define your own converters by simply defining a class that inherits from `Converter` and implements the required `convert` methods.
However, some **out-of-the-box converters** are already provided by the library.
All OOTB converters have been implemented as Singletons that allow to retrieve their instance through method `get_instance`.
Here follows the list of self-explanatory converters:
- **BoolConverter**
- **CharConverter**
- **DoubleConverter**
- **FloatConverter**
- **IntConverter**
- **LongConverter**
- **LongDoubleConverter**
- **LongLongConverter**
- **PathConverter**
- **UnsignedConverter**
- **UnsignedLongConverter**
- **UnsignedLongLongConverter**

### Example Code Snippet
``` c++
int main(int argc, char** argv){
    ArgumentParser parser(argc, argv);

    parser.add_argument(NamedArgument<string>("name", "arg1")); // Positional arg named arg1

    parser.add_argument(NamedArgument<string>("name", "--arg2")); // Optional arg named --arg2

    parser.add_argument( // Optional arg with abbreviation
        NamedArgument<string>("name", "--arg-abbr"),
        NamedArgument<string>("abbreviation", "-t"),
        NamedArgument<string>("help_string", "This is just a test string to show how to pass a help string")
    );

    parser.add_argument( // Optional arg with default value
        NamedArgument<string>("name", "--def-val"),
        NamedArgument<string*>("default_val", new string("This is a default value"))
    );
    
    parser.add_argument( // Required optional argument
        NamedArgument<string>("name", "arg6"),
        NamedArgument<bool>("is_required", true)
    );
    
    parser.add_argument( // Multi-value argument
        NamedArgument<string>("name", "--list-arg"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND),
        NamedArgument<string>("dest", "custom_dest")
    );

    parser.add_argument( // True flag argument
        NamedArgument<string>("name", "--this-is-true"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::STORE_TRUE)
    );

    parser.add_argument( // False flag argument
        NamedArgument<string>("name", "--this-is-false"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::STORE_FALSE)
    );
    
    parser.add_argument( // Multi-value argument with default value (parsed values will be appended)
        NamedArgument<string>("name", "--list-arg"),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND),
        NamedArgument<std::vector<string>*>("default_val", new std::vector<string>{"my", "name", "is", "Kris"})
    );
    
    parser.add_argument( // OOTB Converter
        NamedArgument<string>("name", "--int-arg"),
        NamedArgument<Converter*>("arg_converter", IntConverter::get_instance())
    );

    parser.add_argument( // Custom Converter multi-value argument
        NamedArgument<string>("name", "--custom"),
        NamedArgument<Converter*>("arg_converter", new CustomConverter()),
        NamedArgument<ArgumentAction>("action", ArgumentAction::APPEND)
    );

    ArgumentsMap args = parser.parse_args();

    std::cout << "Parsed arguments:" << std::endl;

    string s;
    args["--arg-abbr"]->get_value(&s);
    std::cout << "Value: " << s << std::endl << std::endl;

    std::vector<string> v;
    args["custom_dest"]->get_value(&v);
    std::cout << "Value: " << pprint_vector(v) << std::endl << std::endl;

    int n;
    args["--int-arg"]->get_value(&n);
    std::cout << "Value: " << n << std::endl << std::endl;
```
