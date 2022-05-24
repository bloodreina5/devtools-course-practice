// Copyright 2022 Kruglov Aleksei

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/App.h"

int main(int argc, const char** argv) {
    PermutationsApp app;
    std::string output = app(argc, argv);
    std::cout << output << "\n";
    return 0;
}
