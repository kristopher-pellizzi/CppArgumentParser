#ifndef ARGSMAP
#define ARGSMAP

#include "Argument.h"
#include <string>
#include <map>

using std::string;

namespace AP{
    class ArgumentsMap{
        private:
            std::map<string, Argument> args;

        public:
            ArgumentsMap(const std::map<string, Argument>& init);

            std::map<string, Argument>::iterator begin();
            std::map<string, Argument>::iterator end();
            const Argument& operator[](const string& key);
    };
}

#endif // ARGSMAP