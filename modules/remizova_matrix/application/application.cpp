// Copyright 2022 Groshev Nikolay

#include <string>
#include <iostream>
#include "include/matrix_app.h"

int main(int argc, const char** argv) {
  MatrixCalculator app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
