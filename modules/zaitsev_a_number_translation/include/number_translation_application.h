// Copyright 2022 Kamenev Ilya

#ifndef MODULES_ZAITSEV_A_NUMBER_TRANSLATION_INCLUDE_NUMBER_TRANSLATION_APPLICATION_H_
#define MODULES_ZAITSEV_A_NUMBER_TRANSLATION_INCLUDE_NUMBER_TRANSLATION_APPLICATION_H_

#include <string>
#include <vector>

enum class ConsoleOperation {
  translating_a_word_into_a_number,
  translating_a_number_into_a_word
};

class NumberTranslationApp {
 public:
  NumberTranslationApp();

  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateArguments(int argc, const char** argv);

  std::string m_message;
};

#endif  // MODULES_ZAITSEV_A_NUMBER_TRANSLATION_INCLUDE_NUMBER_TRANSLATION_APPLICATION_H_
