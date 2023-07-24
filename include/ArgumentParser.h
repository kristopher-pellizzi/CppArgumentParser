#ifndef ARGUMENTPARSER
#define ARGUMENTPARSER

#include <vector>
#include <string>
#include <set>
#include "ArgumentDefinition.h"

using std::string;

namespace AP{
    class ArgumentParser{
        private:
            int argc;
            std::vector<string> argv;
            std::set<ArgumentDefinition> optional_arg_defs;
            std::vector<ArgumentDefinition> positional_arg_defs;

            void add_optional_arg(ArgumentDefinition& arg);
            void add_positional_arg(ArgumentDefinition& arg);

        public:
            ArgumentParser(int argc, char** argv);
            ArgumentParser(const ArgumentParser& ap);
            ArgumentParser& operator=(const ArgumentParser& ap);

            void add_argument(string name, string value = "", string help_string = "");
            void parse_args() const;
    };
}

#endif // ARGUMENTPARSER