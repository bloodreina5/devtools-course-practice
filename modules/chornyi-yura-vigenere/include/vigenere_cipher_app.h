// Copyright 2022 Ershov Alexey

#ifndef MODULES_CHORNYI_YURA_VIGENERE_INCLUDE_VIGENERE_CIPHER_APP_H_
#define MODULES_CHORNYI_YURA_VIGENERE_INCLUDE_VIGENERE_CIPHER_APP_H_

#include <stdexcept>
#include <string>

class VigenereApplication {
 public:
  VigenereApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
  std::string cipher_error(const std::invalid_argument& e);
};

#endif  // MODULES_CHORNYI_YURA_VIGENERE_INCLUDE_VIGENERE_CIPHER_APP_H_
