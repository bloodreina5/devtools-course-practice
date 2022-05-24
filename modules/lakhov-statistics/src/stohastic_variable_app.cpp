// Copyright 2022 Dydykin Pavel

#include <string>
#include <stdexcept>
#include <vector>

#include "../include/stohastic_variable_app.h"
#include "../include/stohastic_variable.h"

StohasticVariableApp::StohasticVariableApp() {}

std::string StohasticVariableApp::operator() (int argc, const char** argv) {
    if (argc != 2 && argc != 4) {
        return this->argument_error();
    }

    std::string arg1 = std::string(argv[1]);
    if (arg1 == "--help" || arg1 == "-h") {
        return this->help();
    }

    try {
        std::vector<double> v1;
        std::vector<double> v2;
        std::string arg2 = std::string(argv[2]);
        std::string arg3 = std::string(argv[3]);

        size_t k = 0;
        std::string tmp = "";
        while (k < arg2.length()) {
            if (arg2[k] == ',') {
                v1.push_back(std::stoi(tmp));
                tmp = "";
                k++;
                continue;
            }
            tmp += arg2[k];
            k++;
            if (k == arg2.length()) {
                v1.push_back(std::stoi(tmp));
                break;
            }
        }

        k = 0;
        tmp = "";
        while (k < arg3.length()) {
            if (arg3[k] == ',') {
                v2.push_back(std::stod(tmp));
                tmp = "";
                k++;
                continue;
            }

            tmp += arg3[k];
            k++;
            if (k == arg3.length()) {
                v2.push_back(std::stod(tmp));
                break;
            }
        }

        StohasticVariable sc(v1, v2);

        if (arg1 == "1") {
            return std::to_string(sc.RawMoment(2));
        } else if (arg1 == "2") {
            return std::to_string(sc.Mean());
        } else if (arg1 == "3") {
            return std::to_string(sc.CentralMoment(3));
        } else if (arg1 == "4") {
            return std::to_string(sc.Dispersion());
        } else {
            return "Incorrect number of operation";
        }
    }
    catch (std::invalid_argument& e) {
        return this->app_error(e);
    }
}

std::string StohasticVariableApp::help() {
    std::string help = std::string("")
        + "Welcome to stohatic variable app!\n"
        + "Please provide mathematical expression to be calculated\n"
        + "The first number is type of operation: \n"
        + "1 - Raw Moment; 2 - Mean; 3 - Central Moment; 4 - Dispersion \n"
        + "Then two vectors of distribution density";
    return help;
}

std::string StohasticVariableApp::argument_error() {
    std::string error = std::string("")
        + "Invalid argument amount, try --help or -h command";
    return error;
}

std::string StohasticVariableApp::app_error(const std::invalid_argument& e) {
    std::string error = std::string("")
        + "Calculational error occured!\n"
        + e.what();
    return error;
}
