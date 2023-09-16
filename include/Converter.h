#ifndef ARG_CONVERTER
#define ARG_CONVERTER

#include <string>
#include <vector>
#include "errors/ArgumentConversionException.h"

using std::string;

namespace AP{
    class Converter{
        public:
            virtual void convert(void* ptr, const string& s) = 0;
            virtual void convert(void* ptr, const std::vector<string>& v) = 0;
    };
}

#endif // ARG_CONVERTER