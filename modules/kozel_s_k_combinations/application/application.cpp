// Copyright 2022 Soldatov Gleb

#include <iostream>
#include <string>
#include "include/combinations_application.h"

int main(int argc, const char** argv) {
    combinations_App app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
