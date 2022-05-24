// Copyright 2022 Ermakov Pavel
#include <iostream>

#include "include/betcher_app.h"

int main(int argc, const char* argv[]) {
  Application app;
  auto output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
