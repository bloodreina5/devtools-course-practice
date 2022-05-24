// Copyright 2022 Gudkov Andrey
#include <stdbool.h>
#include <limits>
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include "include/segment_tree_app.h"
#include "include/segment_tree.h"


std::string Application::operator()(int argc, const char* argv[]) {
  if (argc == 1) {
        return this->getHelp(argv[0]);
  }
  SegmentTree tree;
  tree.init(10);
  int value = 10;
  tree.set(5, value);
  tree.set(1, value);
  tree.set(9, value);
  std::string output {};
  int l;
  int r;
  int res;
  try {
      auto num = std::stoi(argv[1]);
      auto num2 = std::stoi(argv[2]);
      l = num;
      r = num2;
      if (num < 0) throw std::domain_error {"negative value"};
    } catch(std::exception& e) {
      std::cout << "Error in arguments " << ":"
                << std::endl
                << e.what()
                << std::endl << std::endl;
        return this->getHelp(argv[0]);
    }
  res = tree.sum(l, r);
  output = std::to_string(res);
  return output;
}

std::string Application::getHelp(const char* appname) {
  return std::string {"Segment tree\nUsage: "}
    + std::string {appname}
    + std::string {" Enter two numbers N M\n        Where N & M are integers"};
}
