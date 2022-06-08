// Copyright 2022 Kozel Svetlana

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Complex_Number_Tests, init) {
    double re = 0.1;
    double im = 0.1;

    ComplexNumber num(re, im);

    EXPECT_EQ(re, num.getRe());
    EXPECT_EQ(im, num.getIm());
}

TEST(Complex_Number_Tests, substraction) {
    double re1 = 4.0;
    double im1 = 4.0;

    double re2 = 5.0;
    double im2 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 - z2;

    EXPECT_EQ(-1, z3.getRe());
    EXPECT_EQ(2, z3.getIm());
}

TEST(Complex_Number_Tests, addition) {
    ComplexNumber z1(2, 1);
    ComplexNumber z2(1, 2);

    ComplexNumber z3 = z1 + z2;

    ASSERT_EQ(z3.getRe(), 3);
    ASSERT_EQ(z3.getIm(), 3);
}

TEST(Complex_Number_Tests, multiply) {
    double re1 = 2.0;
    double im1 = 1.0;

    double re2 = 3.0;
    double im2 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;

    EXPECT_EQ(4, z3.getRe());
    EXPECT_EQ(7, z3.getIm());
}

TEST(Complex_Number_Tests, division) {
    ComplexNumber z1(1, 1);
    ComplexNumber z2(1, 1);

    ComplexNumber z3 = z1 / z2;

    ASSERT_EQ(z3.getRe(), 1);
}

TEST(Complex_Number_Tests, compare) {
    double re1 = 5.0;
    double im1 = 5.0;

    double re2 = 5.0;
    double im2 = 5.0;

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);

    EXPECT_EQ(num1, num2);
}

