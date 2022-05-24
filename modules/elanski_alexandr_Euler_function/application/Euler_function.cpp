// Copyright 2022 Gleb "belgad" Danshin
#include <iostream>

#include "include/Euler_function_app.h"

int main(int argc, const char* argv[]) {
  Application app;
  auto output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
