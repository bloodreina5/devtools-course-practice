// Copyright 2022 Elanskiy Alexandr

#ifndef MODULES_BELYAEV_VOLUME_FIGURES_INCLUDE_VFIG_APPLICATION_H_
#define MODULES_BELYAEV_VOLUME_FIGURES_INCLUDE_VFIG_APPLICATION_H_

#include <math.h>
#include <string>

#include "include/Vfig.h"

class Application {
 private:
     std::string getHelp(const std::string& appname);
     bool checkArgument(const std::string& str);
     int parseArgument(const char* arg);
 public:
     std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_BELYAEV_VOLUME_FIGURES_INCLUDE_VFIG_APPLICATION_H_
