// Copyright 2022 Bakina Kseniia

#ifndef MODULES_GUDKOV_A_COMMON_POSLED_INCLUDE_APPLICATION_H_
#define MODULES_GUDKOV_A_COMMON_POSLED_INCLUDE_APPLICATION_H_

#include <string>
#include "include/gudkov_a_common_posled.h"

class Application {
 public:
    std::string operator()(int argc, const char** argv);
 private:
    bool is_correct_data(int argc, const char** argv);
    std::string help();
};

#endif  // MODULES_GUDKOV_A_COMMON_POSLED_INCLUDE_APPLICATION_H_
