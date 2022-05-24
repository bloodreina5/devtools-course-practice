// Copyright 2022 Vanyushkov Maxim

#include <iostream>
#include <string>

#include "include/interpolation_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output << '\n';
    return 0;
}
