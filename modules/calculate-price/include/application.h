// Copyright 2022 Krivosheev Miron

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_APPLICATION_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_APPLICATION_H_

#include <array>
#include <string>

class CalculateBooksPriceApp {
 public:
  CalculateBooksPriceApp();
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_APPLICATION_H_
