// Copyright 2022 Elanskiy Alexandr
#include <gtest/gtest.h>

#include "include/Euler_function.h"

TEST(Function_Euler, test_with_2) {
    EulerFunction f;
    EXPECT_EQ(1, f.Calculate(2));
}

TEST(Function_Euler, test_with_1) {
    EulerFunction f;
    EXPECT_EQ(1, f.Calculate(1));
}

TEST(Function_Euler, test_with_3) {
    EulerFunction f;
    EXPECT_EQ(2, f.Calculate(3));
}

TEST(Function_Euler, test_with_4) {
    EulerFunction f;
    EXPECT_EQ(2, f.Calculate(4));
}

TEST(Function_Euler, test_with_5) {
    EulerFunction f;
    EXPECT_EQ(4, f.Calculate(5));
}

TEST(Function_Euler, test_with_5_plus_5) {
    EulerFunction f;
    EXPECT_EQ(4, f.Calculate(5 + 5));
}

TEST(Function_Euler, test_with_46_minus_9) {
    EulerFunction f;
    EXPECT_EQ(36, f.Calculate(46 - 9));
}

TEST(Function_Euler, test_with_5x5) {
    EulerFunction f;
    EXPECT_EQ(20, f.Calculate(5*5));
}

TEST(Function_Euler, test_with_90_share_3) {
    EulerFunction f;
    EXPECT_EQ(8, f.Calculate(90/3));
}
