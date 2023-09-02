#include "ArgumentProperties.h"

using namespace NA;

bool ArgumentProperties::is_required(){
    return required;
}

void* ArgumentProperties::get_default_val(){
    return default_val;
}