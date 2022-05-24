// Copyright 2022 Krivosheev Miron

#include <string>
#include "include/application.h"
#include "include/calculate_price.h"

CalculateBooksPriceApp::CalculateBooksPriceApp() : message_("") {}

void CalculateBooksPriceApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is an application to calculate Harry Potter books price.\n\n" +

    "There ara 5 different Harry Potter books," +
    "one copy of any of the five books costs 8 EUR.\n" +

    "If, however, you buy two different books, you get a 5%" +
    "discount on those two books.\n" +

    "If you buy 3 different books, you get a 10% discount.\n" +

    "If you buy 4 different books, you get a 20% discount.\n" +

    "If you go the whole hog, and buy all 5, you get a huge 25% discount.\n\n"

    "Note that if you buy, say, four books, of which 3 are" +
    "different titles, you get a 10% discount on the 3 that" +
    "form part of a set, but the fourth book still costs 8 EUR.\n" +

    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " ";
  for (int i = 1; i < 6; i++)
    message_ += "<number of books in the " + std::to_string(i) + " volume> ";
}

bool CalculateBooksPriceApp::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 6) {
    help(argv[0], "ERROR: Should be 5 arguments.\n\n");
    return false;
  }
  return true;
}

std::string CalculateBooksPriceApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;

  int num_of_books[5];
  for (int i = 1; i < argc; i++)
    num_of_books[i - 1] = std::stoi(argv[i]);
  CalculatePrice res(num_of_books[0], num_of_books[1],
    num_of_books[2], num_of_books[3], num_of_books[4]);
  message_ = std::to_string(res.TotalSum());
  return message_;
}
