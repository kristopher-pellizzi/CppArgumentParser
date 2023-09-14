#ifndef INVALID_ARG_NAME_EXC
#define INVALID_ARG_NAME_EXC

#include <exception>
#include <string>
#include "ArgumentAction.h"

using std::string;

namespace AP{
    class IncompatibleActionException : public std::exception{
        private:
            string given;

        public:
            IncompatibleActionException(ArgumentAction given);
            virtual const char* what() const throw();
    };
}

#endif // INVALID_ARG_NAME_EXC