// Copyright 2022 Krapivenskikh Stepan

#include <iostream>
#include <string>

#include "include/hanoi_tower_application.h"

int main(int argc, const char** argv) {
  HanoiTowerApp app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
