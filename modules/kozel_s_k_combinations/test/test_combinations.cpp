// Copyright 2022 Kozel Svetlana

#include <gtest/gtest.h>

#include <vector>

#include "include/combinations.h"

TEST(combinations_in_array, test0) {
    int res;
    combinations cnm;
    res = cnm.get_cnm();
    ASSERT_EQ(2, res);
}

TEST(combinations_in_array, test1) {
    int res;
    combinations cnm(6, 4);
    res = cnm.get_cnm();
    ASSERT_EQ(15, res);
}

TEST(combinations_in_array, test2) {
    combinations cnm(6, 12);
    EXPECT_ANY_THROW(cnm.get_cnm());
}

TEST(combinations_in_array, test3) {
    int res;
    combinations cnm(5, 4);
    res = cnm.get_cnm();
    ASSERT_EQ(5, res);
}

TEST(combinations_in_array, test4) {
    int res;
    combinations cnm(3, 2);
    res = cnm.get_cnm();
    ASSERT_EQ(3, res);
}

TEST(combinations_in_array, test5) {
    int res;
    combinations cnm(10, 10);
    res = cnm.get_cnm();
    ASSERT_EQ(1, res);
}
