// Copyright 2022 Kruglov Aleksei

#ifndef MODULES_LUKASHUK_D_PG_INCLUDE_APP_H_
#define MODULES_LUKASHUK_D_PG_INCLUDE_APP_H_

#include <string>
#include "PermutationGeneration.h"

class PermutationsApp {
 public:
    std::string operator()(int argc, const char** argv);
 private:
    bool isValid(std::string* out, int argc, const char** argv);
    std::string help();
};

#endif  // MODULES_LUKASHUK_D_PG_INCLUDE_APP_H_
