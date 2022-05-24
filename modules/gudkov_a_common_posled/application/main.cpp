// Copyright 2022 Bakina Kseniia

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
