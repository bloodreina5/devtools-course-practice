// Copyright 2022 Butescu Vladimir
#ifndef MODULES_RADIX_SORT_DYDYKIN_INCLUDE_RADIX_SORT_APP_H_
#define MODULES_RADIX_SORT_DYDYKIN_INCLUDE_RADIX_SORT_APP_H_

#include <string>
#include "include/radix_sort.h"

class RadixSortApplication {
 public:
  RadixSortApplication();
  std::string operator()(int argc, const char** argv);
 private:
  bool check_args(int argc, const char** argv);
  void help(const char* appname, const char* message = "");
  std::string message_;
  typedef struct {
      double first;
      double second;
      double third;
      double fouth;
      double fifth;
  } Arguments;
};

#endif  // MODULES_RADIX_SORT_DYDYKIN_INCLUDE_RADIX_SORT_APP_H_
