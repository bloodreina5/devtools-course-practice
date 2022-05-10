// Copyright 2022 Gordeev Viktor

#ifndef MODULES_PICHUGIN_I_SORT_INCLUDE_SORT_SELECTION_APPLICATION_H_
#define MODULES_PICHUGIN_I_SORT_INCLUDE_SORT_SELECTION_APPLICATION_H_

#include <string>

#include "include/sort_selection.h"

class SortSelectionApplication {
 private:
    int parseArgument(const char* arg);
 public:
    SortSelectionApplication();
    std::string operator()(int argc, const char** argv);
    std::string getHelp(const std::string& appname);
};

#endif  // MODULES_PICHUGIN_I_SORT_INCLUDE_SORT_SELECTION_APPLICATION_H_
