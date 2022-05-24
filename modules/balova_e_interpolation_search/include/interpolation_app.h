// Copyright 2022 Vanyushkov Maxim

#ifndef MODULES_BALOVA_E_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_APP_H_
#define MODULES_BALOVA_E_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_APP_H_

#include <string>

#include "include/interpolation_search.h"

class Application {
 private:
     std::string getHelp(const std::string& app_name);
     bool checkArgument(const std::string& str);
     int parseArgument(const char* arg);
 public:
     std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_BALOVA_E_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_APP_H_
