// Copyright 2022 Krivosheev Miron

#include "include/bit_array.h"
#include <string>

BitArray::BitArray() {
  arr = NULL;
  size = 0;
  bitSize = 0;
}

BitArray::BitArray(const unsigned int _bitSize) {
  size = _bitSize / 8  + 1;
  bitSize = _bitSize;
  arr = new char[size];
  for (int i = 0; i < static_cast<int>(size); i++)
    arr[i] = 0;
}

BitArray::BitArray(const BitArray& arrCopy) {
  bitSize = arrCopy.bitSize;
  size = arrCopy.size;
  arr = new char[size];
  for (int i = 0; i < static_cast<int>(size); i++)
    arr[i] = arrCopy.arr[i];
}

int BitArray::GetSizeBits() {
  return bitSize;
}

void BitArray::SetBit(unsigned int bitPos, bool val) {
  if (bitPos >= size * 8)
    throw std::string("Out of range");
  int pos = bitPos / 8;
  arr[pos] = arr[pos] | (static_cast<int>(val) << (7 - bitPos % 8));
}

bool BitArray::GetBit(unsigned int bitPos) {
  if (bitPos >= size * 8)
    throw std::string("Out of range");
  int pos = bitPos / 8;
  return arr[pos] & 1 << (7 - bitPos % 8);
}

bool BitArray::IsEmpty() {
  return size == 0 && bitSize == 0 && arr == NULL;
}

void BitArray::DeleteArray() {
  if (arr == NULL)
    throw std::string("Array alrady NULL");
  for (int i = 0; i < static_cast<int>(size); i++)
    arr[i] = 0;
  delete[] arr;
  size = 0;
  bitSize = 0;
  arr = NULL;
}

void BitArray::AllocateArray(int _bitSize) {
  if (arr != NULL)
    throw std::string("You can't allocate array while it isn't NULL, "
      "delete array at first");
  bitSize = _bitSize;
  size = bitSize / 8 + 1;
  arr = new char[size];
  for (unsigned int i = 0; i < size; i++)
    arr[i] = 0;
}
