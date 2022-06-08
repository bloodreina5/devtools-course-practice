// Copyright 2022 Vitulin Ivan

#ifndef MODULES_SHILOV_R_BIG_INT_INCLUDE_BIG_INT_APPLICATION_H_
#define MODULES_SHILOV_R_BIG_INT_INCLUDE_BIG_INT_APPLICATION_H_

#include <string>

#include "include/big_int.h"

class BigIntApplication {
 private:
    BigInt left;
    BigInt right;

    const std::string operators[11] = { "+", "-", "*", "/", "%", ">", ">=",
                                        "<", "<=", "==", "!=" };
    int operator_ind = -1;

    bool readArguments(int argc, const char** argv);
    std::string calculate();

 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_SHILOV_R_BIG_INT_INCLUDE_BIG_INT_APPLICATION_H_
