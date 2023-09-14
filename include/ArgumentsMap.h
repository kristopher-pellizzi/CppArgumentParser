#ifndef ARGSMAP
#define ARGSMAP

#include "IArgument.h"
#include <string>
#include <map>

using std::string;

namespace AP{
    class ArgumentsMap{
        private:
            std::map<string, IArgument*> args;

        public:
            ArgumentsMap(const std::map<string, IArgument*>& init);

            std::map<string, IArgument*>::iterator begin();
            std::map<string, IArgument*>::iterator end();
            IArgument* operator[](const string& key);
    };
}

#endif // ARGSMAP