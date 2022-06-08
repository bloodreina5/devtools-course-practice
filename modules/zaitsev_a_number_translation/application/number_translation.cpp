// Copyright 2022 Kamenev Ilya

#include <iostream>
#include <string>

#include "include/number_translation_application.h"

int main(int argc, const char** argv) {
  NumberTranslationApp app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
