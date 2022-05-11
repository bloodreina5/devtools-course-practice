  // Copyright 2022 Andrich Maria

#include <gtest/gtest.h>
#include "include/SortFacility.h"

TEST(Sort_Facility, test_zero) {
	Sort s;
	const char* input = " ";
	char output[128];

	ASSERT_NO_THROW(s.shunting_yard(input, output));
}

TEST(Sort_Facility, test_one_argument) {
	Sort s;
	const char* input = "q";
	char output[128];

	s.shunting_yard(input, output);

	std::string answer = output;

	ASSERT_EQ(answer, "q");
}

TEST(Sort_Facility, test_simple_equation) {
	Sort s;
	const char* input = "a = b + c";
	char output[128];

	s.shunting_yard(input, output);

	std::string answer = output;
	ASSERT_EQ(answer, "abc+=");
}

TEST(Sort_Facility, test_equation) {
	Sort s;
	const char* input = "a = b + c * d - f";
	char output[128];

	s.shunting_yard(input, output);

	std::string answer = output;
	ASSERT_EQ(answer, "abcd*+f-=");
}

TEST(Sort_Facility, test_difficult_equation) {
	Sort s;
	const char* input = "a = D(f - b * c + d, !e, g)";
	char output[128];

	s.shunting_yard(input, output);

	std::string answer = output;
	ASSERT_EQ(answer, "afbc*-d+e!gD=");
}
