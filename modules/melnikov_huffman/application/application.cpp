// Copyright 2022 Bulicheva Darya
#include <iostream>

#include "include/huffman_code_app.h"

int main(int argc, const char* argv[]) {
    Application app;
    auto output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
