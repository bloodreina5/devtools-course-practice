// Copyright 2022 Alimov Mikhail

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/alimov_calculator.h"

int main(int argc, const char** argv) {
    ComplexCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
