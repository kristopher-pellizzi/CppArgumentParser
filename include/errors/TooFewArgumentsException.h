#ifndef TOO_FEW_ARG_EXC
#define TOO_FEW_ARG_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class TooFewArgumentsException : public std::exception{
        private:
            unsigned expected;
            unsigned given;

        public:
            TooFewArgumentsException(unsigned expected, unsigned given);
            virtual const char* what() const throw();
    };
}

#endif // TOO_FEW_ARG_EXC