#ifndef INVALID_ABBREVIATION_EXCEPTION
#define INVALID_ABBREVIATION_EXCEPTION

#include <exception>
#include <string>

using std::string;

namespace AP{
    class InvalidAbbreviationException : public std::exception{
        private:
            string abbreviation;

        public:
            InvalidAbbreviationException(string abbreviation);
            virtual const char* what() const throw();
    };
}

#endif // INVALID_ABBREVIATION_EXCEPTION