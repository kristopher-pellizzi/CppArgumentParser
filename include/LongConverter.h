#ifndef LONGCONVERTER
#define LONGCONVERTER

#include "Converter.h"

namespace AP{
    class LongConverter : public Converter{
        private:
            static LongConverter* instance;

            LongConverter();

        public:
            LongConverter(const LongConverter& other) = delete;
            LongConverter& operator=(const LongConverter& other) = delete;

            static LongConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // LONGCONVERTER