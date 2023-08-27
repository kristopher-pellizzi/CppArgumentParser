#ifndef ARGUMENTDEF
#define ARGUMENTDEF

#include <string>

using std::string;

namespace AP{
    class ArgumentDefinition{
        private:
            string name;
            string help_string;
            string* default_val;
            bool is_required;

            static bool is_alphanumeric(char c);
            static bool is_valid_name(string name);

        public:
            ArgumentDefinition(string name, string help_string, string* default_val, bool is_required);
            ArgumentDefinition(const ArgumentDefinition& other);
            ArgumentDefinition& operator=(const ArgumentDefinition& other);
            ~ArgumentDefinition();

            string get_name() const;
            string get_help_string() const;
            string* get_default_val() const;
            bool get_is_required();
            bool is_optional() const;

            friend bool operator<(const ArgumentDefinition& l, const ArgumentDefinition& r);
            friend bool operator<(const ArgumentDefinition& l, const string& r);
            friend bool operator<(const string& l, const ArgumentDefinition& r);
    };
}

#endif // ARGUMENTDEF