#ifndef UNSIGNEDLONGCONVERTER
#define UNSIGNEDLONGCONVERTER

#include "Converter.h"

namespace AP{
    class UnsignedLongConverter : public Converter{
        private:
            static UnsignedLongConverter* instance;

            UnsignedLongConverter();

        public:
            UnsignedLongConverter(const UnsignedLongConverter& other) = delete;
            UnsignedLongConverter& operator=(const UnsignedLongConverter& other) = delete;

            static UnsignedLongConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // UNSIGNEDLONGCONVERTER