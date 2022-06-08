// Copyright 2022 Zaitseva Ksenia

#ifndef MODULES_DEICSTRA_ALGORITHM_INCLUDE_DEICSTRA_APPLICATION_H_
#define MODULES_DEICSTRA_ALGORITHM_INCLUDE_DEICSTRA_APPLICATION_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "include/ershov_alexey_deicstra_algorithm.h"

class DeicstraApplication {
 public:
  std::string operator()(int argc, const char* argv[]);

 private:
  template <typename T>
  std::string toString(T val);
  bool help(int argc, const char* argv[], std::size_t* top,
            std::vector<std::vector<std::size_t>>* graf);
  bool checkGraf(const std::vector<std::vector<std::size_t>>& graf);
};

template <typename T>
inline std::string DeicstraApplication::toString(T val) {
  std::ostringstream oss;
  oss << val;
  return oss.str();
}

#endif  // MODULES_DEICSTRA_ALGORITHM_INCLUDE_DEICSTRA_APPLICATION_H_
