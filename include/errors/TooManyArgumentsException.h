#ifndef TOO_MANY_ARG_EXC
#define TOO_MANY_ARG_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class TooManyArgumentsException : public std::exception{
        private:
            unsigned expected;
            unsigned given;

        public:
            TooManyArgumentsException(unsigned expected, unsigned given);
            virtual const char* what() const throw();
    };
}

#endif // TOO_MANY_ARG_EXC