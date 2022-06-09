// Copyright 2022 Andrich Maria

#include <string>
#include <algorithm>
#include <vector>
#include "include/levenshtein_distance_app.h"
#include "include/levenshtein_distance.h"

std::string LevenshteinApp::help(const char* appname) {
    return std::string { "Haffman code\nUsage: " }
    + std::string{ appname };
}

std::string LevenshteinApp::operator()(int argc, const char* argv[]) {
    if (argc == 1 || argc > 2) {
        return this->help(argv[0]);
    }
    std::string const& source{};
    std::string const& target{};
    std::vector<std::vector<int>> lev_dist(source.length() + 1,
        std::vector<int>(target.length() + 1));
    lev_dist[0][0] = 0;
}

