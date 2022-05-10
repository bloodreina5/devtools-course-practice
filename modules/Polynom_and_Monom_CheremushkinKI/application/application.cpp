// Copyright 2022 Troegubova Alexandra

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Polynom_app.h"

int main(int argc, const char** argv) {
    PolynomCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
