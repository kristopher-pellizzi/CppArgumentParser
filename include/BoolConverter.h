#ifndef BOOLCONVERTER
#define BOOLCONVERTER

#include "Converter.h"

namespace AP{
    class BoolConverter : public Converter{
        private:
            static BoolConverter* instance;

            BoolConverter();

        public:
            BoolConverter(const BoolConverter& other) = delete;
            BoolConverter& operator=(const BoolConverter& other) = delete;

            static BoolConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // BOOLCONVERTER