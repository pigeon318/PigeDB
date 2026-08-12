#include "../include/type.h"
#include <iostream>

int main() {
    std::cout << "is true a boolean " << pigedb::isBoolean("true") << "\n";
    std::cout << "is false a boolean " << pigedb::isBoolean("false") << "\n";
    std::cout << "is hi a boolean " << pigedb::isBoolean("hi") << "\n";
    std::cout << "is 12345 a int " << pigedb::isInteger("12345") << "\n";
    std::cout << "is true a int " << pigedb::isInteger("true") << "\n";
    std::cout << "is 1.2 a decimal " << pigedb::isDecimal("1.2") << "\n";
    std::cout << "is 1.23456 a decimal " << pigedb::isDecimal("1.23456") << "\n";
    std::cout << "is hello a decimal " << pigedb::isDecimal("hello") << "\n";
    std::cout << "is hello.1 a decimal " << pigedb::isDecimal("hello.1") << "\n";

}