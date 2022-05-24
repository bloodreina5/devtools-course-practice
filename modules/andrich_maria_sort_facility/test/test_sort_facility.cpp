  // Copyright 2022 Andrich Maria

#include <gtest/gtest.h>
#include <string>
#include "include/SortFacility.h"

TEST(Sort_Facility, test_zero) {
Sort s;
char* input = " ";
char output[128];
ASSERT_NO_THROW(s.shunting_yard(input, output));
}

TEST(Sort_Facility, test_one_argument) {
Sort s;
char* input = "q";
char output[128];

s.shunting_yard(input, output);

std::string answer = output;

ASSERT_EQ(answer, "q");
}

TEST(Sort_Facility, test_simple_equation) {
Sort s;
char* input = "a = b + c1";
char output[128];

s.shunting_yard(input, output);

std::string answer = output;
ASSERT_EQ(answer, "abc1+=");
}

TEST(Sort_Facility, test_equation) {
Sort s;
char* input = "a = b + c1 * d - f";
char output[128];

s.shunting_yard(input, output);

std::string answer = output;
ASSERT_EQ(answer, "abcd*+f-=");
}

TEST(Sort_Facility, test_difficult_equation) {
Sort s;
char* input = "a = D(f - b * c1 + d, !e, g)";
char output[128];

s.shunting_yard(input, output);

std::string answer = output;
ASSERT_EQ(answer, "afbc*-d+e!gD=");
}
