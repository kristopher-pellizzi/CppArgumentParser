#ifndef CHARCONVERTER
#define CHARCONVERTER

#include "Converter.h"

namespace AP{
    class CharConverter : public Converter{
        private:
            static CharConverter* instance;

            CharConverter();

        public:
            CharConverter(const CharConverter& other) = delete;
            CharConverter& operator=(const CharConverter& other) = delete;

            static CharConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // CHARCONVERTER