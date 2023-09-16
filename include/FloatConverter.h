#ifndef FLOATCONVERTER
#define FLOATCONVERTER

#include "Converter.h"

namespace AP{
    class FloatConverter : public Converter{
        private:
            static FloatConverter* instance;

            FloatConverter();

        public:
            FloatConverter(const FloatConverter& other) = delete;
            FloatConverter& operator=(const FloatConverter& other) = delete;

            static FloatConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // FLOATCONVERTER