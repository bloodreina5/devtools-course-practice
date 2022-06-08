// Copyright 2022 Shelepin Nikita

#ifndef MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_APPLICATION_H_
#define MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_APPLICATION_H_

#include <string>
#include <vector>

class BMApplication {
 public:
  BMApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  // MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_APPLICATION_H_
