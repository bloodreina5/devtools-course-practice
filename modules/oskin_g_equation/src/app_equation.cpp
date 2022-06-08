// Copyright 2022 Cheremushkin Kirill
#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include "include/app_equation.h"
std::string appEquation::getHelp(const std::string& appname) {
    return "This is an application to demonstrate"
        " the operation of the calculating the kvadratnoe uravleniy\n"
        "Format for arguments:\n"
        + appname + " <a> <b> <c> \n"
        "All arguments are not Zero\n";
}

bool appEquation::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9'|| str[i] == '-')
            return false;
    }
    return true;
}

int appEquation::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Wrong argument type");
    return std::stoi(arg);
}

std::string appEquation::operator()(int argc, const char** argv) {
    double a, b, c;
    double res[2] = {0, 0};

    if (argc == 1)
        return getHelp(argv[0]);
    try {
        if (argc < 4) {
            std::string error_msg = std::to_string(argc);
            throw std::runtime_error(error_msg);
        }
        if (argc > 4) {
            std::string error_msg = "Should be 3 argument";
            throw std::runtime_error(error_msg);
        }
        std::cout << argc << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << argv[i] << std::endl;
        }
        a = parseArgument(argv[1]);
        b = parseArgument(argv[2]);
        c = parseArgument(argv[3]);
    }
    catch (std::exception& exp) {
        return exp.what();
    }

    Equation bv = Equation(a, b, c);
    Equation::SolveEQ(bv, res);
    std::ostringstream oss;
    oss << res[0] << ", " << res[1];
    return oss.str();
}
