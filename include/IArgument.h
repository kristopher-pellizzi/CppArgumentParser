#ifndef ABSTR_ARG
#define ABSTR_ARG

#include "ArgumentDefinition.h"

namespace AP{
    class IArgument{
        friend class ArgumentParser;

        private:
            virtual void get_raw_value(void* container) const = 0;

        public: 
            virtual ~IArgument() = 0;

            virtual void get_value(void* container) const = 0;
            virtual string get_name() const = 0;
            virtual bool is_multivalue() const = 0;
            virtual ArgumentAction get_action() const = 0;
    };
}

#endif // ABSTR_ARG