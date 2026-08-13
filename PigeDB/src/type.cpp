#include "../include/type.h"
#include <cctype>

namespace pigedb {
    Type detectType(const std::string &value) {

        Type type = Type::Text;

        if (isDecimal(value) == true) {
             type = Type::Decimal;
        }
        else if (isBoolean(value) == true) {
             type = Type::Boolean;
        }
        else if (isInteger(value) == true) {
             type = Type::Integer;
        }
        else if (isDate(value) == true) {
             type = Type::Date;
        }

        return type;

    }


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

    int year =
        (value[0] - '0') * 1000 +
        (value[1] - '0') * 100 +
        (value[2] - '0') * 10 +
        (value[3] - '0');

    int month =
        (value[5] - '0') * 10 +
        (value[6] - '0');

    int day =
        (value[8] - '0') * 10 +
        (value[9] - '0');

    if (month < 1 || month > 12)
        return false;

    int daysInMonth;

    switch (month)
    {
        case 2:
            if ((year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0))
            {
                daysInMonth = 29;
            }
            else
            {
                daysInMonth = 28;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;

        default:
            daysInMonth = 31;
            break;
    }

    return day >= 1 && day <= daysInMonth;
}
}




