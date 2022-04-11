// Copyright 2022 Andrich Maria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Andrich_Maria_ComplexNumberTest, addition) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber num(re, im);

  EXPECT_EQ(re, num.getRe());
  EXPECT_EQ(im, num.getIm());
}

TEST(Andrich_Maria_ComplexNumberTest, Sum) {
  double re = 3.0;
  double im = 2.5;
  double re1 = 2.0;
  double im1 = 1.5;

  ComplexNumber a(re, im);
  ComplexNumber b(re1, im1);
  ComplexNumber c = a + b;

  EXPECT_EQ(5.0, c.getRe());
  EXPECT_EQ(4.0, c.getIm());
}

TEST(Andrich_Maria_ComplexNumberTest, Divide_by_zero) {
  double re = 1.7;
  double im = 0.8;
  double re1 = 0.0;
  double im1 = 0.0;

  ComplexNumber a(re, im);
  ComplexNumber b(re1, im1);

  ASSERT_ANY_THROW(a / b);
}

TEST(Andrich_Maria_ComplexNumberTest, Comparison) {
  double re = 2.0;
  double im = 3.0;

  double re1 = 2.0;
  double im1 = 3.0;

  ComplexNumber a(re, im);
  ComplexNumber b(re1, im1);

  EXPECT_EQ(a, b);
}
