// Copyright 2022 Elanskiy Alexandr

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/Vfig_application.h"
#include "include/Vfig.h"

std::string Application::getHelp(const std::string& appname) {
    return "This is an application to demonstrate"
    " the operation of the calculating the volume of a cube\n"
    "Format for arguments:\n"
    + appname + " <left_border> <right_border> \n"
    "Where all the first arguments must be no greater than the second\n";
}

std::string Application::operator()(int argc, const char** argv) {
    int a, b;
    double result;

    if (argc == 1)
        return getHelp(argv[0]);

    try {
        if (argc == 2) {
            std::string error_msg = "Should be 2 argument";
            throw std::runtime_error(error_msg);
        }
        if (argc > 3) {
            std::string error_msg = "Should be 2 argument";
            throw std::runtime_error(error_msg);
        }
        a = parseArgument(argv[1]);
        b = parseArgument(argv[2]);
        if (a > b) {
            std::string error_msg = "First arg more than second";
            throw std::runtime_error(error_msg);
        }
    }

    catch (std::exception& exp) {
        return exp.what();
    }

    Body_Volume bv;
    result = bv.calculation_volume_cube(a, b);
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
        throw std::runtime_error("Wrong argument type");
    return std::stoi(arg);
}
