#ifndef ARGUMENTACTION
#define ARGUMENTACTION

#include <iostream>

namespace AP{
    enum class ArgumentAction{
        STORE,
        STORE_TRUE,
        STORE_FALSE,
        APPEND
    };


}

std::ostream& operator<<(std::ostream& out, const AP::ArgumentAction& action);


#endif // ARGUMENTACTION