//
// Created by spark on 12/08/2026.
//

#ifndef PIGEDB_TYPE_H
#define PIGEDB_TYPE_H

#include <string>

namespace pigedb {

    enum class Type {
        Null,
        Integer,
        Decimal,
        Boolean,
        Text,
        Date,
        DateTime,
        Binary
    };

    Type detectType(const std::string& value);

    bool isInteger(const std::string& value);
    bool isDecimal(const std::string& value);
    bool isBoolean(const std::string& value);
    bool isDate(const std::string& value);
    bool isDatetime(const std::string& value);

}

#endif //PIGEDB_TYPE_H
