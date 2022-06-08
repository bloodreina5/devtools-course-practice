// Copyright 2022 Likashuk Diana

#include <iostream>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    BitArrayApp app;
    std::string output = app(argc, argv);
    std::cout << output;
    return 0;
}
