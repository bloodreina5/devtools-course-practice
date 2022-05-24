// Copyright 2022 Miheev Ivan

#ifndef MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_APP_H_
#define MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_APP_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  // MODULES_OLYNIN_A_CROSS_LINE_AND_PLANE_INCLUDE_CROSS_LINE_AND_PLANE_APP_H_
