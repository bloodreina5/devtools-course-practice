// Copyright 2022 Bulicheva Darya

#include <gtest/gtest.h>

#include <vector>

#include "include/bil_interpol.h"

TEST(bilinear_interpolation, default_construct) {
    bilen_interpol bl;
    double res = bl.interpolate();
    EXPECT_EQ(res, 10);
}

TEST(bilinear_interpolation, test_with_integer) {
    std::vector<double> arr = { 55, 9, 11, 23 };
    bilen_interpol bl(arr);
    double res = bl.interpolate();
    EXPECT_EQ(res, 24.5);
}

TEST(bilinear_interpolation, test_with_double) {
    std::vector<double> arr = { 5.5, 1.9, 10.1, 7.4 };
    bilen_interpol bl(arr);
    double res = bl.interpolate();
    EXPECT_EQ(res, 6.225);
}

TEST(bilinear_interpolation, test1_with_int_and_double) {
    std::vector<double> arr = { 5.5, 9, 69, 4.2 };
    bilen_interpol bl(arr);
    double res = bl.interpolate();
    EXPECT_EQ(res, 21.925);
}

TEST(bilinear_interpolation, test2_with_int_and_double) {
    std::vector<double> arr = { 50, 10, 9, 22.7 };
    bilen_interpol bl(arr);
    double res = bl.interpolate();
    EXPECT_EQ(res, 22.925);
}

TEST(bilinear_interpolation, test_with_negative_value) {
    std::vector<double> arr = { -50, 10.3, 10.1, 22.6 };
    bilen_interpol bl(arr);
    double res = bl.interpolate();
    EXPECT_EQ(res, -1.75);
}
