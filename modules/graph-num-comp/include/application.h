// Copyright 2022 Melnikov Aleksei

#ifndef MODULES_GRAPH_NUM_COMP_INCLUDE_APPLICATION_H_
#define MODULES_GRAPH_NUM_COMP_INCLUDE_APPLICATION_H_

#include <array>
#include <string>

class NumCompApp {
 public:
  NumCompApp();
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_GRAPH_NUM_COMP_INCLUDE_APPLICATION_H_
