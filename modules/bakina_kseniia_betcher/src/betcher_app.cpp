// Copyright 2022 Ermakov Pavel
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include "include/backina_kseniia_betcher.h"
#include "include/betcher_app.h"

std::string Application::operator()(int argc, const char* argv[]) {
  if (argc == 1) {
        return this->getHelp(argv[0]);
  }
  std::vector<int> vector;
  std::vector<int> vector2;
  std::vector<int> result;
  std::string output {};
  for (auto i = 1; i < argc; i++) {
    try {
      auto num = std::stoi(argv[i]);
      vector.push_back(num);
      vector2.push_back(num);
      if (num <= 0) throw std::domain_error {"negative value"};
    } catch(std::exception& e) {
      std::cout << "Error in argument " << i << ":"
                << std::endl
                << e.what()
                << std::endl << std::endl;
        return this->getHelp(argv[0]);
    }
  }
  EvenOddBetcher::partial_merger(0, vector, vector2, &result);
  for (int i = 0; i < argc; i++) {
      output += std::to_string(result[i]);
      output += std::string { " " };
  }
  return output;
}

std::string Application::getHelp(const char* appname) {
  return std::string {"Betcher Odd even merge\nUsage: "}
    + std::string {appname}
    + std::string {" N devided with spaces\n        Where N are integers"};
}
