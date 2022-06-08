// Copyright 2022 Oskin Georgii & Cheremushkin Kirill
#include <gtest/gtest.h>

#include "include/equation.h"

TEST(EqConstructor, Constructor_WO_Params) {
    ASSERT_NO_THROW(Equation eq);
}

TEST(EqConstructor, Constructor_W_Params) {
    ASSERT_NO_THROW(Equation eq(2.0, 5.0, 3.0));
}

TEST(EqConstructor, Constructor_W_Minus) {
    ASSERT_NO_THROW(Equation eq(-5.0, 2.0, 1.0));
}

TEST(EqConstructor, Exept_ON_NON_R_ROOTS) {
    ASSERT_ANY_THROW(Equation eq(1, 2, 3));
}

TEST(SolveEQ_test, Can_Solve_Default) {
    // Arrange
    double res[2];
    Equation eq;
    // Act & Assert
    Equation::SolveEQ(eq, res);
    ASSERT_TRUE((res[0] == 1) && (res[1] == -1.5));
}

TEST(SolveEQ_test, Can_Solve_WO_B) {
    // Arrange
    double res[2];
    Equation eq(2.0, 0.0, -18.0);

    // Act & Assert
    Equation::SolveEQ(eq, res);
    ASSERT_TRUE((res[0] == 3) && (res[1] == -3));
}

TEST(SolveEQ_test, Can_Solve_WO_C) {
    // Arrange
    double res[2];
    Equation eq(2.0, -18.0, 0.0);

    // Act & Assert
    Equation::SolveEQ(eq, res);
    ASSERT_TRUE((res[0] == 0) && (res[1] == 9));
}
