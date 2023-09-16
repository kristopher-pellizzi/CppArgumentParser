#ifndef INTCONVERTER
#define INTCONVERTER

#include "Converter.h"

namespace AP{
    class IntConverter : public Converter{
        private:
            static IntConverter* instance;

            IntConverter();

        public:
            IntConverter(const IntConverter& other) = delete;
            IntConverter& operator=(const IntConverter& other) = delete;

            static IntConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // INTCONVERTER