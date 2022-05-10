// Copyright 2022 Troegubova Alexandra

#ifndef MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_APP_H_
#define MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_APP_H_

#include "Polynom.h"

#include <string>

class PolynomCalculator {
 public:
    PolynomCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        Polynom polynom_1;
        Polynom polynom_2;
        char operation;
    } Arguments;
};

#endif  // MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_APP_H_
