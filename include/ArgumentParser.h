#ifndef ARGUMENTPARSER
#define ARGUMENTPARSER

#include <vector>
#include <string>
#include <set>
#include <map>
#include "ArgumentDefinition.h"
#include "Argument.h"
#include "ArgumentsMap.h"

using std::string;

namespace AP{
    class ArgumentParser{
        private:
            int argc;
            std::vector<string> argv;
            unsigned argv_index;
            std::set<ArgumentDefinition, std::less<>> optional_arg_defs;
            std::vector<ArgumentDefinition> positional_arg_defs;
            unsigned num_parsed_positional_args;
            std::set<string> required_opt_parameters;
            std::map<string, Argument> parsed_arguments;

            void add_optional_arg(ArgumentDefinition& arg);
            void add_positional_arg(ArgumentDefinition& arg);
            void parse_optional_arg(string str_arg);
            void parse_positional_arg(string str_arg);
            void parse_arg(string str_arg);

        public:
            ArgumentParser(int argc, char** argv);
            ArgumentParser(const ArgumentParser& ap);
            ArgumentParser& operator=(const ArgumentParser& ap);

            void add_argument(string name, string help_string = "", string* default_val = NULL, bool is_required = false);
            ArgumentsMap parse_args();
    };
}

#endif // ARGUMENTPARSER