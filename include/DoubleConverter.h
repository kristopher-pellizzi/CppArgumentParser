#ifndef DOUBLECONVERTER
#define DOUBLECONVERTER

#include "Converter.h"

namespace AP{
    class DoubleConverter : public Converter{
        private:
            static DoubleConverter* instance;

            DoubleConverter();

        public:
            DoubleConverter(const DoubleConverter& other) = delete;
            DoubleConverter& operator=(const DoubleConverter& other) = delete;

            static DoubleConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // DOUBLECONVERTER