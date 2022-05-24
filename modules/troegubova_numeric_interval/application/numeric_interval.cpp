// Copyright 2022 Petrova Polina



#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "../include/numeric_interval_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
