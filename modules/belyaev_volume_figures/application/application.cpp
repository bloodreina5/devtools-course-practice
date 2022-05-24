// Copyright 2022 Elanskiy Alexandr

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Vfig_application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
