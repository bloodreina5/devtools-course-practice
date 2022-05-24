// Copyright 2022 Shatalin Dmitrii
#ifndef MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_ALIMOV_MIKE_CEACER_CIFIR_APPLICATION_H_
#define MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_ALIMOV_MIKE_CEACER_CIFIR_APPLICATION_H_

#include <string>
#include "include/alimov_mike_ceacer_cifir.h"

class Application {
 private:
    std::string getHelp(const std::string& appname);
    bool checkArgument(const std::string& str);
    int parseArgument(const char* arg);
 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_ALIMOV_MIKE_CEACER_CIFIR_APPLICATION_H_
