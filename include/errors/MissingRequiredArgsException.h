#ifndef MISSING_REQUIRED_ARGS_EXC
#define MISSING_REQUIRED_ARGS_EXC

#include <exception>
#include <string>
#include <set>

using std::string;

namespace AP{
    class MissingRequiredArgsException : public std::exception{
        private:
            std::set<string>& missing_args;

        public:
            MissingRequiredArgsException(std::set<string>& missing_args);
            virtual const char* what() const throw();
    };
}

#endif // MISSING_REQUIRED_ARGS_EXC