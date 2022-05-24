// Copyright 2022 Borisov Maxim

#ifndef MODULES_ERMAKOV_PAVEL_TRINGLE_PARAMS_INCLUDE_TRIANGLE_APP_H_
#define MODULES_ERMAKOV_PAVEL_TRINGLE_PARAMS_INCLUDE_TRIANGLE_APP_H_

#include <string>
#include <utility>

#include "./ermakov_pavel_tringle_params.h"

class application {
 public:
  struct arguments {
    std::pair<float, float> a;
    std::pair<float, float> b;
    std::pair<float, float> c;
    std::string operation{""};
    int side{0};
  };

 public:
  std::string operator()(int argc, char** argv);

 private:
  std::string help(const std::string& appname);
  bool validate(const std::string& str);
  arguments parse_args(int argc, char** argv);
};

#endif  // MODULES_ERMAKOV_PAVEL_TRINGLE_PARAMS_INCLUDE_TRIANGLE_APP_H_

