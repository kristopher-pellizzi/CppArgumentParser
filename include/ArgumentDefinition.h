#ifndef ARGUMENTDEF
#define ARGUMENTDEF

#include <string>

using std::string;

namespace AP{
    class ArgumentDefinition{
        private:
            string name;
            string help_string;

            static bool is_alphanumeric(char c);
            static bool is_valid_name(string name);

        public:
            ArgumentDefinition(string name, string help_string);
            string get_name() const;
            string get_help_string() const;
            bool is_optional() const;

            friend bool operator<(const ArgumentDefinition& l, const ArgumentDefinition& r);
            friend bool operator<(const ArgumentDefinition& l, const string& r);
            friend bool operator<(const string& l, const ArgumentDefinition& r);
    };
}

#endif // ARGUMENTDEF