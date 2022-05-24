// Copyright 2022 Kim Nikita

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "include/app.h"

int main(int argc, const char** argv) {
  LongerApp app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
