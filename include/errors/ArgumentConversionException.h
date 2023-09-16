#ifndef ARG_CONVERSION_EXC
#define ARG_CONVERSION_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class ArgumentConversionException : public std::exception{
        private:
            string msg;
            string arg;

        public:
            ArgumentConversionException(string msg, string arg);
            virtual const char* what() const throw();
    };
}

#endif // ARG_CONVERSION_EXC