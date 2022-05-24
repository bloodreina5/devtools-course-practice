// Copyright 2022 Trevogin Kirill

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


#include "include/borisov_m_pos_systems_calculator.h"
#include "include/cal_app.h"

std::string Application::getHelp(const std::string& appname) {
    return "This is an application to demonstrate"
           " the calculation profit with deposit\n"
           "Format for arguments:\n"
        + appname + " <amount> <years> <percent> \n"
                    "Argument must be positive!\n";
}

std::string Application::operator()(int argc, const char** argv) {
    std::string amount;
    std::string years;
    std::string percent;

    if (argc == 1)
        return getHelp(argv[0]);
    try {
        if (argc > 4) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 3 argument.\nYou entered more!\n";
            throw std::runtime_error(error_msg);
        }
        amount = parseArgument(argv[1]);
        years = argv[2];
        percent = parseArgument(argv[3]);
    } catch (std::exception& exp) {
        return exp.what();
    }
    calculator cls(amount);
    std::ostringstream oss;
    switch (years[0]) {
    case '/':
       oss<< cls / percent;
        break;
    case '*':
        oss << cls * percent;
        break;
    case '+':
        oss << cls + percent;
        break;
    case '-':
        oss << cls - percent;
        break;
    }
    return oss.str();
}

bool Application::checkArgument(const std::string& str) {
    return true;
}

int Application::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Error occured: Wrong argument type.\n");
    return std::stoi(arg);
}
