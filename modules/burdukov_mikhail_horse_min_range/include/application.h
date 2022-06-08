// Copyright 2022 Melnikov Aleksei

#ifndef MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_APPLICATION_H_
#define MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_APPLICATION_H_

#include <array>
#include <string>
#include <vector>
#include <utility>

class HorseMinRangeApp {
 public:
  HorseMinRangeApp();
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_APPLICATION_H_
