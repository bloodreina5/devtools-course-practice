// Copyright 2022 Shatalin Dmitry

#ifndef MODULES_SHATALIN_DMITRII_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APPLICATION_H_
#define MODULES_SHATALIN_DMITRII_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APPLICATION_H_

#include <string>

#include "include/deposit_calculator.h"

class Application {
 private:
    std::string getHelp(const std::string& appname);
    bool checkArgument(const std::string& str);
    int parseArgument(const char* arg);
 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_SHATALIN_DMITRII_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APPLICATION_H_
