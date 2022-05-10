// Copyright 2022 Ershov Alexey

#include <iostream>
#include <string>

#include "include/vigenere_cipher_app.h"

int main(int argc, const char** argv) {
  VigenereApplication app;
  std::string result = app(argc, argv);
  std::cout << result << std::endl;
  return 0;
}
