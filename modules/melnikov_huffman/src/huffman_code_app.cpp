// Copyright 2022 Bulicheva Darya
#include "include/huffman_code_app.h"
#include "include/huffman_code.h"

#include <map>

#include <exception>
#include <iostream>
#include <string>

std::string Application::operator()(int argc, const char* argv[]) {
    if (argc == 1 || argc > 2) {
        return this->help(argv[0]);
    }
    std::string output {};
    MinHeap c1;
    std::map<char, std::string> canonical_codes;
    std::string a;
    if (argc == 2) {
        canonical_codes[1] = "a";
        a = argv[1];
        output = c1.get_encoded_text(a, canonical_codes);
    }
    return output;
}

std::string Application::help(const char* appname) {
    return std::string { "Haffman code\nUsage: " }
    + std::string { appname }
    + std::string { " Enter <text>\n        Where <text> is string" };
}
