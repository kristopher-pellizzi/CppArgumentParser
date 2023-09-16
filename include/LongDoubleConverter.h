#ifndef LONGDOUBLECONVERTER
#define LONGDOUBLECONVERTER

#include "Converter.h"

namespace AP{
    class LongDoubleConverter : public Converter{
        private:
            static LongDoubleConverter* instance;

            LongDoubleConverter();

        public:
            LongDoubleConverter(const LongDoubleConverter& other) = delete;
            LongDoubleConverter& operator=(const LongDoubleConverter& other) = delete;

            static LongDoubleConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // LONGDOUBLECONVERTER