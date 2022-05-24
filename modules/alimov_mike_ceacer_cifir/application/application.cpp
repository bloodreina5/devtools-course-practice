// Copyright 2022 Shatalin Dmitrii

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/alimov_mike_ceacer_cifir_application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
