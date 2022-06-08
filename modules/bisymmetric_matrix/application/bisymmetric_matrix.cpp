// Copyright 2022 Shelepin Nikita

#include <iostream>
#include <string>

#include "include/bisymmetric_matrix_application.h"

int main(int argc, const char** argv) {
  BMApplication app;
  std::string output = app(argc, argv);
  std::cout << output;
  return 0;
}
