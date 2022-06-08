// Copyright 2022 Vitulin IVan

#include <iostream>

#include "include/big_int_application.h"

int main(int argc, const char* argv[]) {
    BigIntApplication app;
    auto output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
