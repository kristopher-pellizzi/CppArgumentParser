#ifndef PATHCONVERTER
#define PATHCONVERTER

#include <filesystem>
#include "Converter.h"

namespace AP{
    class PathConverter : public Converter{
        private:
            static PathConverter* instance;

            PathConverter();

        public:
            PathConverter(const PathConverter& other) = delete;
            PathConverter& operator=(const PathConverter& other) = delete;

            static PathConverter* get_instance();
            void convert(void* ptr, const string& s);
            void convert(void* ptr, const std::vector<string>& v);
    };
}

#endif // PATHCONVERTER