// Copyright 2022 Krivosheev Mrion

#ifndef MODULES_KRIVOSHEEV_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define MODULES_KRIVOSHEEV_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <string>

class BitArray {
 private:
  char* arr;
  unsigned int bitSize;
  unsigned int size;
 public:
  BitArray();
  explicit BitArray(const unsigned int _bitSize);
  BitArray(const BitArray& arrCopy);
  int GetSizeBits();
  void SetBit(unsigned int bitPos, bool val);
  bool GetBit(unsigned int bitPos);
  bool IsEmpty();
  void DeleteArray();
  void AllocateArray(int _bitSize);
};

#endif  // MODULES_KRIVOSHEEV_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
