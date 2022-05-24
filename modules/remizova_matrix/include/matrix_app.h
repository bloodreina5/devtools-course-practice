// Copyright 2022 Remizova Antonina & Grohev Nikolay
#include <string>
#include <vector>
#include "include/remizova_a_matrix.h"
#ifndef MODULES_REMIZOVA_MATRIX_INCLUDE_MATRIX_APP_H_
#define MODULES_REMIZOVA_MATRIX_INCLUDE_MATRIX_APP_H_


class MatrixCalculator {
 public:
  MatrixCalculator();
  std::string operator()(int argc, const char** argv);

 private:
  void helpMessage(const char* message);
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
  std::string RunOperations(int argc, TMatrix<double> m1, TMatrix<double> m2,
                            int operation);
};
#endif  // MODULES_REMIZOVA_MATRIX_INCLUDE_MATRIX_APP_H_
