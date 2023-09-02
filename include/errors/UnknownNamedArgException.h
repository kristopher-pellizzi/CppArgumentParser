#ifndef UNKNOWN_NAMED_ARG_EXC
#define UNKNOWN_NAMED_ARG_EXC

#include <exception>
#include <string>

using std::string;

namespace NA{
    class UnknownNamedArgumentException : public std::exception{
        private:
            string arg_name;

        public:
            UnknownNamedArgumentException(string arg_name);
            virtual const char* what() const throw();
    };
}

#endif // UNKNOWN_NAMED_ARG_EXC