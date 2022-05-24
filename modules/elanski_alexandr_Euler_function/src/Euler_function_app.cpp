// Copyright 2022 Gleb "belgad" Danshin
#include <exception>
#include <iostream>
#include <string>

#include "include/Euler_function_app.h"
#include "include/Euler_function.h"

std::string Application::operator()(int argc, const char* argv[]) {
  if (argc == 1) {
    return this->help(argv[0]);
  }
  std::string output {};
  for (auto i = 1; i < argc;) {
    try {
      auto num = std::stoi(argv[i]);
      if (num <= 0) throw std::domain_error {"negative value"};
      output += std::to_string(EulerFunction::Calculate(num));
    } catch(std::exception& e) {
      std::cout << "Error in argument " << i << ":"
                << std::endl
                << e.what()
                << std::endl << std::endl;
      return this->help(argv[0]);
    }
    if (++i != argc) {
      output += std::string {" "};
    }
  }
  return output;
}

std::string Application::help(const char* appname) {
  return std::string {"Euler's totient function calculator\nUsage: "}
    + std::string {appname}
    + std::string {" N [N...]\n        Where N are positive integers"};
}
