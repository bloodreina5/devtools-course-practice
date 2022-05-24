// Copyright 2022 Pyatckin Nikolay

#ifndef MODULES_POPP_MAKSIM_TEMPLATE_BINARY_HEAP_INCLUDE_TEMPLATE_HEAP_APP_H_
#define MODULES_POPP_MAKSIM_TEMPLATE_BINARY_HEAP_INCLUDE_TEMPLATE_HEAP_APP_H_

#include <string>
#include <vector>

class Heap_App {
    std::vector<float> Argc_app;

    std::string HelpMessage(const char* appname);
    bool Parsing(int argc, const char** argv);
    bool ValidateNumberOfArguments(int argc, const char** argv);

 public:
    Heap_App() = default;
    Heap_App(const Heap_App&) = default;

    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_POPP_MAKSIM_TEMPLATE_BINARY_HEAP_INCLUDE_TEMPLATE_HEAP_APP_H_
