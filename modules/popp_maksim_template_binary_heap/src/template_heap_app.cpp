// Copyright 2022 Pyatckin Nikolay

#include "include/template_heap.h"
#include "include/template_heap_app.h"

#include <string>
#include <sstream>

std::string Heap_App::HelpMessage(const char* appname) {
    return std::string("") +
        "      This is an application which allows you \n" +
        "      to sort numbers in reverse order\n" +
        "      Please provide arguments in the following format:\n" +
        "         $" + appname + " value_1 value_2 ... value_n\n" +
        "      You can use any data type for numbers\n";
}

bool Heap_App::Parsing(int argc, const char** argv) {
    try {
        for (int i = 1; i < argc; ++i)
            Argc_app.emplace_back(std::stof(argv[i]));
        return true;
    }
    catch (std::exception&) {
        return false;
    }
}

bool Heap_App::ValidateNumberOfArguments(int argc, const char** argv) {
    auto no_argumnets = [&argc] { return argc == 1; };
    auto first_arg_is_help = [&argv] { return std::string(argv[1]) == "help"; };

    if (no_argumnets() || first_arg_is_help()) {
        return false;
    }
    return true;
}

std::string Heap_App::operator()(int argc, const char** argv) {
    std::ostringstream result;
    if (!ValidateNumberOfArguments(argc, argv)) {
        result << HelpMessage(argv[0]) << std::endl;
        return "";
    }

    bool sts;
    sts = Parsing(argc, argv);
    if (sts == false) {
        result << "      Input error\n\n%s" << HelpMessage(argv[0]) << "\n";
    }

    THeap<float> heap(Argc_app);
    for (auto value : heap.GetVectorHeap())
        result << value << " ";
    result << "\n";

    return result.str();
}
