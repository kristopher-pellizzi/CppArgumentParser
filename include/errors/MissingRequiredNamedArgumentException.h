#ifndef MISSING_REQUIRED_NAMED_ARG_EXC
#define MISSING_REQUIRED_NAMED_ARG_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class MissingRequiredNamedArgumentException : public std::exception{
        private:
            string arg_name;

        public:
            MissingRequiredNamedArgumentException(string arg_name);
            virtual const char* what() const throw();
    };
}

#endif // MISSING_REQUIRED_NAMED_ARG_EXC