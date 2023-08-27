#ifndef ARG_KEY_EXC
#define ARG_KEY_EXC

#include <exception>
#include <string>

using std::string;

namespace AP{
    class ArgKeyException : public std::exception{
        private:
            string key;

        public:
            ArgKeyException(string key);
            virtual const char* what() const throw();
    };
}

#endif // ARG_KEY_EXC