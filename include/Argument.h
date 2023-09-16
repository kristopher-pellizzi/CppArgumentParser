#ifndef ARGUMENT
#define ARGUMENT

#include <string>
#include "IArgument.h"

using std::string;

namespace AP{
    template <typename T>
    class Argument : public IArgument{
        private:
            ArgumentDefinition arg_def;
            T value;

            void convert_value(void* container) const;

        public:
            Argument(ArgumentDefinition arg_def, T value);

            void get_value(void* container) const;
            string get_name() const;
            bool is_multivalue() const;
            ArgumentAction get_action() const;
    };
}

#endif // ARGUMENT