// Copyright 2022 Kim Nikita

#ifndef MODULES_TREVOGIN_KIRILL_MAXPOS_INCLUDE_APP_H_
#define MODULES_TREVOGIN_KIRILL_MAXPOS_INCLUDE_APP_H_

#include <string>
#include "include/trevogin_kirill_maxpos.h"

class LongerApp {
 public:
    std::string operator()(int argc, const char** argv);
 private:
    bool check_args(int argc, const char** argv);
    std::string help();
};

#endif  // MODULES_TREVOGIN_KIRILL_MAXPOS_INCLUDE_APP_H_
