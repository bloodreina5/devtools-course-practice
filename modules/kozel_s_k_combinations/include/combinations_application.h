// Copyright 2022 Soldatov Gleb

#ifndef MODULES_KOZEL_S_K_COMBINATIONS_INCLUDE_COMBINATIONS_APPLICATION_H_
#define MODULES_KOZEL_S_K_COMBINATIONS_INCLUDE_COMBINATIONS_APPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/combinations.h"

class combinations_App {
 public:
    combinations_App();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    double parseDouble(const char* arg);
    std::string message_;
};

#endif  // MODULES_KOZEL_S_K_COMBINATIONS_INCLUDE_COMBINATIONS_APPLICATION_H_
