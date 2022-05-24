// Copyright 2022 Lakhov Kirill

#ifndef MODULES_KOROBEINIKOV_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
#define MODULES_KOROBEINIKOV_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_

#include <string>
#include <stdexcept>

class StringCalculatorApp {
 public:
    StringCalculatorApp();
    std::string operator()(int argc, const char** argv);

 private:
    std::string help();
    std::string argument_error();
    std::string calc_error(const std::invalid_argument& e);
};

#endif  // MODULES_KOROBEINIKOV_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
