// Copyright 2022 Gordeev Viktor

#include <cstdio>
#include <string>

#include "include/sort_selection_application.h"

int main(int argc, const char** argv) {
    SortSelectionApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
