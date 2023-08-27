#ifndef ARGUMENT
#define ARGUMENT

#include <string>
#include "ArgumentDefinition.h"

using std::string;

namespace AP{
    class Argument{
        private:
            const ArgumentDefinition& arg_def;
            string value;

        public:
            Argument(const ArgumentDefinition& arg_def, string value);

            string get_value() const;
            string get_name() const;
    };
}

#endif // ARGUMENT