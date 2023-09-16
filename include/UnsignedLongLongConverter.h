#ifndef UNSIGNEDLONGLONGCONVERTER
#define UNSIGNEDLONGLONGCONVERTER

#include "Converter.h"

namespace AP{
    class UnsignedLongLongConverter : public Converter{
        private:
            static UnsignedLongLongConverter* instance;

            UnsignedLongLongConverter();

        public:
            UnsignedLongLongConverter(const UnsignedLongLongConverter& other) = delete;
            UnsignedLongLongConverter& operator=(const UnsignedLongLongConverter& other) = delete;

            static UnsignedLongLongConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // UNSIGNEDLONGLONGCONVERTER