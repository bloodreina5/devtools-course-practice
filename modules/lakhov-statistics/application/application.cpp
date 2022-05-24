// Copyright 2022 Dydykin Pavel

#include <string>
#include <iostream>

#include "../include/stohastic_variable_app.h"

int main(int argc, const char** argv) {
    StohasticVariableApp app;
    std::string result = app(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
