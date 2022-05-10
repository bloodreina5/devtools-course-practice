// Copyright 2022 Narlyyew Parahat

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Narlyyew_Parahat_ComplexNumberTest, Copy_constructor) {
    double re = 1.0;
    double Im = 2.1;
    ComplexNumber a(re, Im);
    ComplexNumber b(a);

    EXPECT_EQ(re, b.getRe());
    EXPECT_EQ(Im, b.getIm());
}

TEST(Narlyyew_Parahat_ComplexNumberTest, Operator_plus) {
    double re = 1.0;
    double Im = 2.1;
    double re2 = 0.1;
    double Im2 = 1.2;

    ComplexNumber a(re, Im);
    ComplexNumber b(re2, Im2);
    ComplexNumber c = a + b;

    EXPECT_EQ(c.getRe(), re + re2);
    EXPECT_EQ(c.getIm(), Im + Im2);
}

TEST(Narlyyew_Parahat_ComplexNumberTest, Operator_division) {
    double re = 2.4;
    double Im = 2.1;
    double re2 = 2.2;
    double Im2 = 1.2;
    double abs_error = 0.1;
    double resRe = 1.2;
    double resIm = 0.2;
    ComplexNumber a(re, Im);
    ComplexNumber b(re2, Im2);
    ComplexNumber c = a / b;

    EXPECT_NEAR(c.getRe(), resRe, abs_error);
    EXPECT_NEAR(c.getIm(), resIm, abs_error);
}
TEST(Narlyyew_Parahat_ComplexNumberTest, Operator_equal_equal) {
    double re = 1.0;
    double Im = 2.1;
    ComplexNumber a(re, Im);
    ComplexNumber b(a);

    EXPECT_TRUE(a == b);
}
