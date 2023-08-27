#ifndef UNKNOWN_ARG_EXC
#define UNKNOWN_ARG_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class UnknownArgumentException : public std::exception{
        private:
            string arg_name;

        public:
            UnknownArgumentException(string arg_name);
            virtual const char* what() const throw();
    };
}

#endif // UNKNOWN_ARG_EXC