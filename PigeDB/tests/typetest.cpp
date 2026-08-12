#include "../include/type.h"
#include <iostream>

int main() {
    std::cout << pigedb::isBoolean("true");
    std::cout << pigedb::isBoolean("false");
    std::cout << pigedb::isBoolean("hi");
}