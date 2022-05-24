// Copyright 2022 Gudkov Andrey

#include <gtest/gtest.h>
#include "include/gudkov_a_common_posled.h"

TEST(Gudkov_common_seq, test_size_0) {
    int res = _common_seq::find_common_seq("", "");
    EXPECT_EQ(res, 0);
}

TEST(Gudkov_common_seq, test_first_size_0) {
    int res = _common_seq::find_common_seq("", "asdasw");
    EXPECT_EQ(res, 0);
}

TEST(Gudkov_common_seq, test_second_size_0) {
    int res = _common_seq::find_common_seq("asdasw", "");
    EXPECT_EQ(res, 0);
}

TEST(Gudkov_common_seq, test_expexted_4) {
    int res = _common_seq::find_common_seq("abcabaac", "baccbca");
    EXPECT_EQ(res, 4);
}

TEST(Gudkov_common_seq, test_on_same_strings) {
    int res = _common_seq::find_common_seq("wadase", "wadase");
    EXPECT_EQ(res, 6);
}
