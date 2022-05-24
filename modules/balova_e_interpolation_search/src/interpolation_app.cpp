// Copyright 2022 Vanyushkov Maxim

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/interpolation_app.h"

std::string Application::getHelp(const std::string& app_name) {
    return  "This is an application to demonstrate"
        " the operation of the interpolation search algorithm\n"
        "Format for arguments:\n" +
        app_name + " <element_to_find> \n"
        "Argument must be positive!\n"
        "Demo array - [-10, -7, -2, 0, 1, 3, 5, 15, 46]";
}

std::string Application::operator()(int argc, const char** argv) {
    int numberToFind;
    int result;
    std::vector<int> demoArr { -10, -7, -2, 0, 1, 3, 5, 15, 46 };
    if (argc == 1) {
        return getHelp(argv[0]);
    }
    try {
        if (argc > 2) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 1 argument.\nYou entered more!\n";
            throw std::runtime_error(error_msg);
        }
        numberToFind = parseArgument(argv[1]);
    }
    catch (std::exception& exp) {
        return exp.what();
    }

    InterpolationSearch<int> is;
    result = is.search(numberToFind, demoArr);

    std::ostringstream oss;
    oss << result;
    return oss.str();
}

bool Application::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != '-' && (str[i] < '0' || str[i] > '9')) {
            return false;
        }
    }
    return true;
}

int Application::parseArgument(const char* arg) {
    if (!checkArgument(arg)) {
        throw std::runtime_error("Error occured: Wrong argument type.\n");
    }
    return std::stoi(arg);
}
