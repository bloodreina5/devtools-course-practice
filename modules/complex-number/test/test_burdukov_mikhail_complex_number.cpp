// Copyright 2022 Burdukov Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Burdukov_Mikhail_ComplexNumberTest, create_comp_number) {
  double r = 4.0;
  double i = 12.0;
  ComplexNumber c(r, i);

  EXPECT_DOUBLE_EQ(4, c.getRe());
  EXPECT_DOUBLE_EQ(12, c.getIm());
}

TEST(Burdukov_Mikhail_ComplexNumberTest, sum_comp_number) {
  double r = 4.0;
  double i = 2.0;
  ComplexNumber c(r, i);

  double r1 = 6.0;
  double i1 = 1.0;
  ComplexNumber c1(r1, i1);

  ComplexNumber res = c1 + c;
  EXPECT_DOUBLE_EQ(10.0, res.getRe());
  EXPECT_DOUBLE_EQ(3.0, res.getIm());
}

TEST(Burdukov_Mikhail_ComplexNumberTest, Subtract) {
  double r = 4.0;
  double i = 2.0;
  ComplexNumber c(r, i);

  double r1 = 6.0;
  double i1 = 1.0;
  ComplexNumber c1(r1, i1);

  ComplexNumber res = c - c1;

  EXPECT_DOUBLE_EQ(-2.0, res.getRe());
  EXPECT_DOUBLE_EQ(1.0, res.getIm());
}

TEST(Burdukov_Mikhail_ComplexNumberTest, compare_comp_number) {
  double r = 4.0;
  double i = 2.0;
  ComplexNumber c(r, i);

  double r1 = 4.0;
  double i1 = 2.0;
  ComplexNumber c1(r1, i1);

  EXPECT_EQ(c1, c);
}

TEST(Burdukov_Mikhail_ComplexNumberTest, multiply_comp_number) {
  double r = 4.0;
  double i = 2.0;
  ComplexNumber c(r, i);

  double r1 = 6.0;
  double i1 = 1.0;
  ComplexNumber c1(r1, i1);

  ComplexNumber res = c1 * c;

  EXPECT_DOUBLE_EQ(22.0, res.getRe());
  EXPECT_DOUBLE_EQ(16.0, res.getIm());
}
