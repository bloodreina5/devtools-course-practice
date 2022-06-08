// Copyright 2022 Zarubin Mikhail

#include <sstream>
#include <cstring>
#include <string>
#include <vector>

#include "include/number_translation.h"
#include "include/number_translation_application.h"

NumberTranslationApp::NumberTranslationApp() : m_message() {}

void NumberTranslationApp::help(const char* appname,
                                        const char* message) {
  std::ostringstream stream;
  stream << message << "This is a number translation application.\n\n"
         << "Please provide arguments in the following format:\n\n"
         <<

      "  $ " << appname << " <value_or_values> "
         << "<operation> <operand>\n\n"
         <<

      "Where argument is string or integer number, "
         << "and <operation> is one of 'translating_a_number_into_a_word' "
         << "or 'translating_a_word_into_a_number'.\n";

  m_message = stream.str();
}

bool validateTypeOfArguments(int argc, const char** argv) {
  for (size_t i = 0; i < strlen(argv[2]); i++) {
    if (!std::isalpha(argv[2][i]) || !std::isblank(argv[2][i])) {
      return false;
    }
  }

  if (std::isdigit(argv[1][0])) {
    for (size_t i = 1; i < strlen(argv[1]); i++) {
      if (!std::isdigit(argv[1][i])) {
        return false;
      }
    }
  } else {
    for (size_t i = 1; i < strlen(argv[1]); i++) {
      if (!std::isalpha(argv[2][i]) || !std::isblank(argv[2][i])) {
        return false;
      }
    }
  }

  return true;
}

bool NumberTranslationApp::validateArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 3) {
    help(argv[0], "ERROR: Should be at least 3 arguments.\n\n");
    return false;
  }

  if (!validateTypeOfArguments(argc, argv)) {
    help(argv[0], "ERROR: Invalid type of argument.");
    return false;
  }

  return true;
}

double tryParseToInt(const char* arg) {
  int result = 0;

  try {
    result = std::stoi(arg);
  } catch (const std::invalid_argument& e) {
    throw std::string("ERROR: Cannot be cast to an integer!");
  } catch (const std::out_of_range& e) {
    throw std::string("ERROR : Number out of range!");
  }

  return result;
}

ConsoleOperation tryParseToOperation(const char* arg) {
  ConsoleOperation operation;

  if (strcmp(arg, "translating_a_number_into_a_word") == 0) {
    operation = ConsoleOperation::translating_a_number_into_a_word;
  } else if (strcmp(arg, "translating_a_word_into_a_number") == 0) {
    operation = ConsoleOperation::translating_a_word_into_a_number;
  } else {
    throw std::string("ERROR: Wrong operation!");
  }

  return operation;
}

std::string NumberTranslationApp::operator()(int argc,
                                                     const char** argv) {
  if (!validateArguments(argc, argv)) {
    return m_message;
  }

  std::vector<int> vectorOfValues;
  ConsoleOperation operation;
  int number = 0;
  std::string word;

  try {
    if (std::isdigit(argv[1][0])) {
      number = tryParseToInt(argv[1]);
    } else {
      for (int i = 1; i < argc - 1; i++) {
        word += argv[i];
      }
    }
    operation = tryParseToOperation(argv[argc - 1]);
  } catch (const std::string& stringException) {
    return stringException;
  }

  std::ostringstream stream;
  translating_a_word_in_a_number word_to_number;
  translating_a_number_in_a_word number_to_word;
  switch (operation) {
    case ConsoleOperation::translating_a_number_into_a_word:
      number_to_word.translating_a_number_into_a_word(number);
      stream << "word: " << number;
      break;
    case ConsoleOperation::translating_a_word_into_a_number:
      word_to_number.translating_a_word_into_a_number(word);
      stream << "number: " << word;
      break;
  }

  m_message = stream.str();
  return m_message;
}
