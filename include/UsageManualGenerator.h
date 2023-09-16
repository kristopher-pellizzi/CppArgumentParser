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