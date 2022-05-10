// Copyright 2022 Gordeev Viktor

#include <iterator>
#include <string>
#include <vector>

#include "include/sort_selection_application.h"

SortSelectionApplication::SortSelectionApplication() { printf("%s\n", ""); }

std::string SortSelectionApplication::getHelp(const std::string& appname) {
    return  "Application started!" \
            "This is a service which help you to sort your array";
}

std::string SortSelectionApplication::
operator()(int argc, const char** argv) {
    if (argc == 1)
        return getHelp(argv[0]);

    try {
        if (argc > 9) {
            std::string error_msg = "Error occurred: Should be less arguments.";
            throw std::runtime_error(error_msg);
        }
        if (argc < 9) {
            std::string error_msg = "Error occurred: Should be more arguments.";
            throw std::runtime_error(error_msg);
        }
        int Arr[]={parseArgument(argv[1]), parseArgument(argv[2]),
                   parseArgument(argv[3]),
                   parseArgument(argv[4]), parseArgument(argv[5]),
                   parseArgument(argv[6]),
                   parseArgument(argv[7]), parseArgument(argv[8])};
        SortSelection res(Arr, 8);

        res.Sort();

        res.Ex(Arr, 8);
    }
    catch (std::exception& exp) {
        return exp.what();
    }
    return "True";
}

int SortSelectionApplication::parseArgument(const char* arg) {
    return std::stoi(arg);
}
