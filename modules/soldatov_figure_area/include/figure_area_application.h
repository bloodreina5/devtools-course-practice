// Copyright 2022 Samoiluk Anastasiya

#ifndef MODULES_SOLDATOV_FIGURE_AREA_INCLUDE_FIGURE_AREA_APPLICATION_H_
#define MODULES_SOLDATOV_FIGURE_AREA_INCLUDE_FIGURE_AREA_APPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/soldatov_figure_area.h"

class figureArea_App {
 public:
    figureArea_App();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    double parseDouble(const char* arg);
    std::string message_;
};

#endif  // MODULES_SOLDATOV_FIGURE_AREA_INCLUDE_FIGURE_AREA_APPLICATION_H_
