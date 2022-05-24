// Copyright 2022 Ermakov Pavel

#ifndef MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BETCHER_APP_H_
#define MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BETCHER_APP_H_

#include <string>
#include <vector>
#include "include/backina_kseniia_betcher.h"

class Application {
 private:
    std::string getHelp(const char* appname);
 public:
    std::string operator()(int argc, const char** argv);
};


#endif  // MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BETCHER_APP_H_
