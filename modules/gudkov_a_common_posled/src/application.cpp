// Copyright 2022 Bakina Kseniia

#include "include/application.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

std::string Application::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return help();
    }
    if (!is_correct_data(argc, argv)) {
        return "Given array must contain two sub-arrays "
            "with printable characters only.";
    }

    std::vector<std::string> input(2);
    for (int i = 1; i < argc; i++) {
        std::string cur(argv[i]);
        input[i - 1] += cur;
    }

    int result = _common_seq::find_common_seq(input[0], input[1]);

    std::string output(std::to_string(result));
    return output;
}

bool Application::is_correct_data(int argc, const char** argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isprint(argv[i][j])) {
                return false;
            }
        }
    }
    return true;
}
std::string Application::help() {
    return "The application searches for the "
        "greatest common subsequence of two given arrays.";
}
