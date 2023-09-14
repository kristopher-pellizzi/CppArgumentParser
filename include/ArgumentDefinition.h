#ifndef ARGUMENTDEF
#define ARGUMENTDEF

#include <string>
#include "ArgumentAction.h"

using std::string;

namespace AP{
    class ArgumentDefinition{
        private:
            string name;
            string help_string;
            void* default_val;
            bool required;
            ArgumentAction action;

            static bool is_alphanumeric(char c);
            static bool is_valid_name(string name);

        public:
            ArgumentDefinition(string name, string help_string, void* default_val, bool required, ArgumentAction action);
            ArgumentDefinition(const ArgumentDefinition& other);
            ArgumentDefinition& operator=(const ArgumentDefinition& other);
            ~ArgumentDefinition();

            string get_name() const;
            string get_help_string() const;
            void* get_default_val() const;
            bool is_required() const;
            bool is_optional() const;
            ArgumentAction get_action() const;

            friend bool operator<(const ArgumentDefinition& l, const ArgumentDefinition& r);
            friend bool operator<(const ArgumentDefinition& l, const string& r);
            friend bool operator<(const string& l, const ArgumentDefinition& r);
    };
}

#endif // ARGUMENTDEF