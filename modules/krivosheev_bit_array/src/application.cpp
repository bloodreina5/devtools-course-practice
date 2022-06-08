// Copyright 2022 Likashuk Diana

#include <iostream>
#include <string>
#include "include/application.h"
#include "include/bit_array.h"

BitArrayApp::BitArrayApp() : message_("") {}

void BitArrayApp::Help(std::string message) {
  message_ =
    std::string(message) +
    "This is an application to get or set bits in bit array.\n\n " +

    "To create array please provide arguments in the following format:" +
    "To set bit: <your bit array> set <num of bit> <value for this bit>\n" +
    "To set bit: <your bit array> get <num of bit>\n";
}

bool BitArrayApp::ParseBitAraayToObj(std::string arr) {
  int N = arr.length();
  bit_arr.AllocateArray(N);
  for (unsigned int i = 0; i < arr.size(); i++) {
    if (arr[i] == '0') {
      bit_arr.SetBit(i, 0);
    } else if (arr[i] == '1') {
      bit_arr.SetBit(i, 1);
  } else {
      Help("Arr must constains just 1 and 0!\n");
      return false;
    }
  }
  return true;
}

std::string  BitArrayApp::BitArrayToString() {
  std::string res = "";
  for (int i = 0; i < bit_arr.GetSizeBits(); i++)
    res += std::to_string(static_cast<int>(bit_arr.GetBit(i)));
  return res;
}

std::string  BitArrayApp::operator()(int argc, const char** argv) {
  if (!ValidateNumberOfArguments(argc, argv))
    return message_;
  if (!ParseBitAraayToObj(argv[1]))
    return message_;
  unsigned int bitPos = std::stoi(argv[3]);
  if (argc == 5) {
    bool val = std::stoi(argv[4]);
    bit_arr.SetBit(bitPos, val);
    message_ = "Your array: " + BitArrayToString();
  } else {  // argc == 4
    bool bit = bit_arr.GetBit(bitPos);
    message_ = "Your bit is " + std::to_string(static_cast<int>(bit));
  }
  return message_;
}

bool BitArrayApp::ValidateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    Help(argv[0]);
    return false;
  } else if (argc != 4 && argc != 5) {
    Help("ERROR: Should be 4 or 5 arguments.\n\n");
    return false;
  }
  return true;
}
