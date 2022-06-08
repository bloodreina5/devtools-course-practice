// Copyright 2022 Belyaev Ilya

#ifndef MODULES_SHELEPIN_N_SIMPSON_INCLUDE_SIMPSON_APP_H_
#define MODULES_SHELEPIN_N_SIMPSON_INCLUDE_SIMPSON_APP_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  //  MODULES_SHELEPIN_N_SIMPSON_INCLUDE_SIMPSON_APP_H_
