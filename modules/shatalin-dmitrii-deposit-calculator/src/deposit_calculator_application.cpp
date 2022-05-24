// Copyright 2022 Brazhnik Dmitry

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


#include "include/deposit_calculator.h"
#include "include/deposit_calculator_application.h"

std::string Application::getHelp(const std::string& appname) {
    return "This is an application to demonstrate"
           " the calculation profit with deposit\n"
           "Format for arguments:\n"
        + appname + " <amount> <years> <percent> \n"
                    "Argument must be positive!\n";
}

std::string Application::operator()(int argc, const char** argv) {
    double amount;
    int years;
    double percent;

    double result;
    if (argc == 1)
        return getHelp(argv[0]);
    try {
        if (argc > 4) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 3 argument.\nYou entered more!\n";
            throw std::runtime_error(error_msg);
        }
        amount = parseArgument(argv[1]);
        years = parseArgument(argv[2]);
        percent = parseArgument(argv[3]);
    } catch (std::exception& exp) {
        return exp.what();
    }

    result = DepositCalculator::calculateDeposit(amount, years, percent);

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
