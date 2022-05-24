// Copyright 2022 Butescu vladimir
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "include/radix_sort.h"
#include "include/radix_sort_app.h"

RadixSortApplication::RadixSortApplication() : message_("") {}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string RadixSortApplication::operator()(int argc, const char** argv) {
    if (!check_args(argc, argv)) {
        return message_;
    }

    RadixSort r;
    Arguments arg;
    std::ostringstream stream;
    std::vector<double> input;
    std::vector<double> output;

    try {
        arg.first = parseDouble(argv[1]);
        arg.second = parseDouble(argv[2]);
        arg.third = parseDouble(argv[3]);
        arg.fouth = parseDouble(argv[4]);
        arg.fifth = parseDouble(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }

    input.push_back(arg.first);
    input.push_back(arg.second);
    input.push_back(arg.third);
    input.push_back(arg.fouth);
    input.push_back(arg.fifth);

    std::string origin = {};
    std::string res = {};

    try {
        output = r.Radix_Sort(input);

        for (int i = 0; i < 5; i++) {
            origin += std::to_string(input[i]);
            origin +=  " ";

            res += std::to_string(output[i]);
            res += " ";
        }

        stream << "Origin = " << origin << " "
            << "Sorted = " << res;
    }
    catch (std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}

bool RadixSortApplication::check_args(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

void RadixSortApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a radix sort application.\n" +
        "Please provide some decimal numbers to sort.\nExample: \n" +
        " $ " + appname + " 1.3 -5.0 10.00 30.23";
}
