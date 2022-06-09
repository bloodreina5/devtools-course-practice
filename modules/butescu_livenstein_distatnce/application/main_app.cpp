// Copyright 2022 Andrich Maria

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "include/levenshtein_distance_app.h"
#include "include/levenshtein_distance.h"

int main(int argc, const char** argv) {
    LevenshteinApp app;
    auto output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
