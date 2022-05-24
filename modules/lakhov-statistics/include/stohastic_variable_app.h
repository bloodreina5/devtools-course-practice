// Copyright 2022 Dydykin Pavel

#ifndef MODULES_LAKHOV_STATISTICS_INCLUDE_STOHASTIC_VARIABLE_APP_H_
#define MODULES_LAKHOV_STATISTICS_INCLUDE_STOHASTIC_VARIABLE_APP_H_

#include <string>
#include <stdexcept>
#include <vector>

class StohasticVariableApp {
 public:
    StohasticVariableApp();
    std::string operator()(int argc, const char** argv);
 private:
    std::string help();
    std::string argument_error();
    std::string app_error(const std::invalid_argument& e);
};

#endif  // MODULES_LAKHOV_STATISTICS_INCLUDE_STOHASTIC_VARIABLE_APP_H_
