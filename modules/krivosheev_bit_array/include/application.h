// Copyright 2022 Likashuk Diana

#ifndef MODULES_KRIVOSHEEV_BIT_ARRAY_INCLUDE_APPLICATION_H_
#define MODULES_KRIVOSHEEV_BIT_ARRAY_INCLUDE_APPLICATION_H_

#include <include/bit_array.h>
#include <array>
#include <string>

class BitArrayApp {
 public:
  BitArray bit_arr;
  std::string message_;
  BitArrayApp();
  std::string operator()(int argc, const char** argv);
 private:
  bool ParseBitAraayToObj(std::string);
  std::string BitArrayToString();
  void Help(std::string message = "");
  bool ValidateNumberOfArguments(int argc, const char** argv);
  void ShowArray();
  void GetBitSize();
  void SetBit(unsigned int bitPos, bool val);
  void GetBit(unsigned int bitPos);
  void IsEmpty();
  void DeleteArray();
  void CreateNewArray(unsigned int size);
};

#endif  // MODULES_KRIVOSHEEV_BIT_ARRAY_INCLUDE_APPLICATION_H_
