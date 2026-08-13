#include "../include/type.h"
#include <iostream>
#include <cctype>

namespace pigedb {

bool isBoolean(const std::string &value) {
    return value == "true" || value == "false";
}
bool isInteger(const std::string &value)
{
    if (value.empty()) {
        return false;
    }

    std::size_t start = 0;
    if (value[0] == '-' || value[0] == '+' ) {
        start = 1;
    }

    if (start == value.size()) {
        return false;
    }

    for (std::size_t i = start; i < value.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(value[i])))
            return false;
    }
    return true;

}
bool isDecimal(const std::string &value) {
    if (value.empty()) {
        return false;
    }
    std::size_t start = 0;
    if (value[0] == '-' || value[0] == '+') {
        start = 1;
    }

    if (start == value.size()) {
        return false;
    }

    bool hasDecimalPoint = false;

    for (std::size_t i = start; i < value.size(); ++i)
    {
        if (value[i] == '.')
        {
            if (hasDecimalPoint) {
                return false;
            }

            hasDecimalPoint = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(value[i])))
        {
            return false;
        }
    }

    return hasDecimalPoint;
}

    bool isDate(const std::string& value)
{
    if (value.size() != 10)
        return false;

    if (value[4] != '-' || value[7] != '-')
        return false;

    for (std::size_t i = 0; i < value.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(static_cast<unsigned char>(value[i])))
            return false;
    }

    return true;
}
}




