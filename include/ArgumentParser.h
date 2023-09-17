#ifndef ARGUMENTPARSER
#define ARGUMENTPARSER

#include <vector>
#include <string>
#include <set>
#include <map>
#include "NamedArgument.h"
#include "ArgumentDefinition.h"
#include "Argument.h"
#include "ArgumentsMap.h"
// Include Argument Converters
#include "BoolConverter.h"
#include "CharConverter.h"
#include "DoubleConverter.h"
#include "FloatConverter.h"
#include "IntConverter.h"
#include "LongConverter.h"
#include "LongDoubleConverter.h"
#include "LongLongConverter.h"
#include "PathConverter.h"
#include "UnsignedConverter.h"
#include "UnsignedLongConverter.h"
#include "UnsignedLongLongConverter.h"

using std::string;
using NA::NamedArgument;

namespace AP{
    class ArgumentParser{
        private:
            int argc;
            std::vector<string> argv;
            unsigned argv_index;
            std::set<ArgumentDefinition, std::less<>> optional_arg_defs;
            std::map<string, string> abbreviation_map;
            std::vector<ArgumentDefinition> positional_arg_defs;
            unsigned num_parsed_positional_args;
            std::set<string> required_opt_parameters;
            std::map<string, IArgument*> parsed_arguments;

            void add_optional_arg(ArgumentDefinition& arg);
            void add_positional_arg(ArgumentDefinition& arg);
            string get_argument_val(const ArgumentDefinition& arg_def);
            void parse_optional_arg(string str_arg);
            void parse_positional_arg(string str_arg);
            void parse_arg(string str_arg);
            void add_argument(string name, string abbreviation, string help_string, string* default_val, bool is_required, ArgumentAction action, string dest, Converter* arg_converter);
            void add_argument(std::map<string, void*>& args);

            template<typename T, typename... Ts>
            void add_argument(std::map<string, void*>& args, NamedArgument<T> arg, Ts... rest){
                args.insert(std::pair<string, void*>(arg.getName(), (void*) arg.getValue()));
                add_argument(args, rest...);
            }

        public:
            ArgumentParser(int argc, char** argv);
            ArgumentParser(const ArgumentParser& ap);
            ArgumentParser& operator=(const ArgumentParser& ap);
            ~ArgumentParser();

            ArgumentsMap parse_args();
            void print_usage_manual() const;
            
            template <typename T, typename... Ts>
            void add_argument(NamedArgument<T> arg, Ts... rest){
                std::map<string, void*> args;

                args.insert(std::pair<string, void*>(arg.getName(), (void*) arg.getValue()));
                add_argument(args, rest...);
            }
    };
}

#endif // ARGUMENTPARSER