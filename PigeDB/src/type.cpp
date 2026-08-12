#include "../include/type.h"
#include <iostream>

namespace pigedb {

bool isBoolean(const std::string &value) {
    return value == "true" || value == "false";
}



}
