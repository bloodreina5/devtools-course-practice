// Copyright 2022 Bulicheva Darya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(ComplexNumber, Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_DOUBLE_EQ(re, z.getRe());
  EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(ComplexNumber, Add) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first + second;
  ASSERT_EQ(product, ComplexNumber(4.0, 6.0));
}

TEST(ComplexNumber, Prod) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first * second;
  ASSERT_EQ(product, ComplexNumber(-5.0, 10.0));
}

TEST(ComplexNumber, Subtract) {
  double re1 = 2.5778;
  double re2 = 5.8765;
  double im1 = 4.4578;
  double im2 = 6.234;
  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber res = c1 - c2;
  double res_re = re1 - re2;
  double res_im = im1 - im2;
  EXPECT_EQ(res.getRe(), res_re);
  EXPECT_EQ(res.getIm(), res_im);
}

TEST(ComplexNumber, Div) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);
  ComplexNumber sum = first / second;
  EXPECT_EQ(1, sum.getRe());
  EXPECT_EQ(0, sum.getIm());
}
