#ifndef INVALID_ARG_NAME_EXC
#define INVALID_ARG_NAME_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class InvalidArgumentNameException : public std::exception{
        private:
            string arg_name;

        public:
            InvalidArgumentNameException(string arg_name);
            virtual const char* what() const throw();
    };
}

#endif // INVALID_ARG_NAME_EXC