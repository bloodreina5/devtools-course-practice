// Copyright 2022 Butescu Vladimir

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/radix_sort_app.h"

int main(int argc, const char** argv) {
RadixSortApplication app;
std::string output = app(argc, argv);
printf("%s\n", output.c_str());
return 0;
}
