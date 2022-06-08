// Copyright 2022 Cheremushkin Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include"include/app_equation.h"
int main(int argc, const char** argv) {
    appEquation app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
