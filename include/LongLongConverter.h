#ifndef LONGLONGCONVERTER
#define LONGLONGCONVERTER

#include "Converter.h"

namespace AP{
    class LongLongConverter : public Converter{
        private:
            static LongLongConverter* instance;

            LongLongConverter();

        public:
            LongLongConverter(const LongLongConverter& other) = delete;
            LongLongConverter& operator=(const LongLongConverter& other) = delete;

            static LongLongConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // LONGLONGCONVERTER