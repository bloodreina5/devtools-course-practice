// Copyright 2022 Krivosheev Mrion
#include <gtest/gtest.h>
#include <string>

#include "include/bit_array.h"

TEST(BitArrayTest, DefaultConstructor) {
  // Arrange
  BitArray arr;

  // Act & Assert
  ASSERT_TRUE(arr.IsEmpty());
}

TEST(BitArrayTest, InitializationConstructor) {
  // Arrange
  BitArray arr(2);

  // Act & Assert
  EXPECT_EQ(2, arr.GetSizeBits());
}

TEST(BitArrayTest, Set_Get) {
  // Arrange
  BitArray arr(2);
  arr.SetBit(0, 1);
  // Act & Assert
  EXPECT_EQ(1, arr.GetBit(0));
}

TEST(BitArrayTest, Set_Get_OutOfRange) {
  // Arrange
  BitArray arr(2);
  ASSERT_ANY_THROW(arr.SetBit(8, 1));
  ASSERT_ANY_THROW(arr.GetBit(8));
}

TEST(BitArrayTest, Set_Get_Feature) {
  // Arrange
  BitArray arr(2);
  arr.SetBit(6, 1);
  EXPECT_EQ(1, arr.GetBit(6));
}

TEST(BitArrayTest, CopyConstructor) {
  // Arrange
  BitArray arr(10);
  for (int i = 0; i < arr.GetSizeBits(); i++)
    arr.SetBit(i, i % 2);
  BitArray arrC(arr);

  // Act & Assert
  for (int i = 0; i < arrC.GetSizeBits(); i++)
    EXPECT_EQ(arr.GetBit(i), arrC.GetBit(i));
}

TEST(BitArrayTest, DeleteArray) {
  // Arrange
  BitArray arr(10);
  arr.DeleteArray();

  // Act & Assert
  ASSERT_TRUE(arr.IsEmpty());
}

TEST(BitArrayTest, DeleteEmptyArray) {
  // Arrange
  BitArray arr;

  // Act & Assert
  ASSERT_ANY_THROW(arr.DeleteArray());
}

TEST(BitArrayTest, AllocateEmptyArray) {
  // Arrange
  BitArray arr;
  arr.AllocateArray(10);

  // Act & Assert
  ASSERT_FALSE(arr.IsEmpty());
}

TEST(BitArrayTest, TryToAllocateMotEmptyArray) {
  // Arrange
  BitArray arr(10);

  // Act & Assert
  ASSERT_ANY_THROW(arr.AllocateArray(20));
}

TEST(BitArrayTest, GetSizeBits) {
  // Arrange
  BitArray arr(10);

  // Act & Assert
  EXPECT_EQ(10, arr.GetSizeBits());
}
