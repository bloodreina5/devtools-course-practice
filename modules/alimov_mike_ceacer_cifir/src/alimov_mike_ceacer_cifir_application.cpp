// Copyright 2022 Shatalin Dmitrii
#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/alimov_mike_ceacer_cifir_application.h"
#include "include/alimov_mike_ceacer_cifir.h"

std::string Application::getHelp(const std::string& appname) {
    return  "This demonstrate caesar's algorithm\n"
        "Format for arguments:\n" +
        appname + " <> \n"
        "Argument must be positive!\n";
}

std::string Application::operator()(int argc, const char** argv) {
    int stro;
    string result;
    if (argc == 1)
        return getHelp(argv[0]);
    try {
        if (argc > 2) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 2 argument.\nYou entered more!\n";
            throw std::runtime_error(error_msg);
        }
        stro = parseArgument(argv[1]);
    }
    catch (std::exception& exp) {
        return exp.what();
    }

    CaesarCipher bs;
    result = bs.encrypt(std::to_string(static_cast<char>(stro)), 2);

    std::ostringstream oss;
    oss << result;
    return oss.str();
}

bool Application::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int Application::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Error occured: Wrong argument type.\n");
    return std::stoi(arg);
}
