// Copyright 2022 Kruglov Aleksei
#include "include/App.h"

#include <string>

std::string PermutationsApp::operator()(int argc, const char** argv) {
    std::string message;
    if (argc == 1) {
        return help();
    }
    if (!isValid(&message, argc, argv)) {
        return message;
    }
    int* array = new int[argc - 1];
    for (int i = 1; i < argc; i++) {
        std::string cur(argv[i]);
        array[i - 1] = std::stoi(cur);
    }
    PermutationGeneration p(array, argc - 1);
    p.do_res();
    int** output = p.get_res();
    std::string res;
    for (int i = 0; i < p.get_size_res(); i++) {
        for (int j = 0; j < p.get_size_inp(); j++) {
            res += (std::to_string(output[i][j]) + " ");
        }
        res += "\n";
    }
    for (int i = 0; i < p.get_size_res(); i++)
        delete[] output[i];
    return res;
}

bool PermutationsApp::isValid(std::string* out, int argc, const char** argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                *out = std::string(argv[i]) +
                       " - contains something else besides digits\n";
                return false;
            }
        }
    }
    return true;
}

std::string PermutationsApp::help() {
    return "The app calculates all permutations of given array";
}
