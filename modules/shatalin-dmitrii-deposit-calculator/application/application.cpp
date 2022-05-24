// Copyright 2022 Brazhnik Dmitry

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/deposit_calculator_application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
