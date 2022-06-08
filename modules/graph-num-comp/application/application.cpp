// Copyright 2022 Melnikov Aleksei

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    NumCompApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
