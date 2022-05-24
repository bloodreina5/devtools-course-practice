// Copyright 2022 Alimov Mikhail

#ifndef MODULES_KAZHAEVA_COMPLEX_INCLUDE_ALIMOV_CALCULATOR_H_
#define MODULES_KAZHAEVA_COMPLEX_INCLUDE_ALIMOV_CALCULATOR_H_

#include <stdio.h>  // NOLIT
#include <stdlib.h>  // NOLIT
#include <stdint.h>  // NOLIT
#include <string.h>  // NOLIT
#include <string>



class ComplexCalculator {
 public:
    ComplexCalculator();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double z1_real;
        double z1_imaginary;
        double z2_real;
        double z2_imaginary;
        char operation;
    } Arguments;
};


#endif  // MODULES_KAZHAEVA_COMPLEX_INCLUDE_ALIMOV_CALCULATOR_H_
