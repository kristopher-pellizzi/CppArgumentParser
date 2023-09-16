#ifndef UNSIGNEDCONVERTER
#define UNSIGNEDCONVERTER

#include "Converter.h"

namespace AP{
    class UnsignedConverter : public Converter{
        private:
            static UnsignedConverter* instance;

            UnsignedConverter();

        public:
            UnsignedConverter(const UnsignedConverter& other) = delete;
            UnsignedConverter& operator=(const UnsignedConverter& other) = delete;

            static UnsignedConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // UNSIGNEDCONVERTER