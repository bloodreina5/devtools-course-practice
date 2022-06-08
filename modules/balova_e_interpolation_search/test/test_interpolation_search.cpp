// Copyright 2022 Balova Elena

#include <gtest/gtest.h>

#include <vector>

#include "include/interpolation_search.h"

TEST(Balova_Elena_Inter_Search_Test, can_create_without_throws) {
    ASSERT_NO_THROW(InterpolationSearch<int>());
}

TEST(Balova_Elena_Inter_Search_Test, can_find_int) {
    std::vector<int> sorted_array = {
        -5, -3, -1, 0, 1, 3, 5
    };
    InterpolationSearch<int> s;
    int result = s.search(0, sorted_array);
    ASSERT_EQ(3, result);
}

TEST(Balova_Elena_Inter_Search_Test, can_find_double) {
    std::vector<double> sorted_array = {
        -5.1, -3.2, -1.3, 0.4, 1.5, 3.6, 5.7
    };
    InterpolationSearch<double> s;
    int result = s.search(1.5, sorted_array);
    ASSERT_EQ(4, result);
}

TEST(Balova_Elena_Inter_Search_Test, correct_work_on_missing_value) {
    std::vector<int> sorted_array = {
        -5, -3, -1, 0, 1, 3, 5
    };
    InterpolationSearch<int> s;
    int result = s.search(10, sorted_array);
    ASSERT_EQ(-1, result);
}

TEST(Balova_Elena_Inter_Search_Test, can_find_int_in_array) {
    const int size = 7;
    int sorted_array[size] = {
        -5, -3, -1, 0, 1, 3, 5
    };
    InterpolationSearch<int> s;
    int result = s.search(0, sorted_array, size);
    ASSERT_EQ(3, result);
}

TEST(Balova_Elena_Inter_Search_Test, search_in_unsorted) {
    std::vector<int> unsorted_array = {
        2, 1, 4, 3, 6, 5, 0
    };
    InterpolationSearch<int> s;
    int result = s.search(4, unsorted_array);
    ASSERT_EQ(-1, result);
}

TEST(Balova_Elena_Inter_Search_Test, first_elem_more_bigger_last) {
    std::vector<int> sorted_array = {
        -100, -1, 0, 0, 2, 3
    };
    InterpolationSearch<int> s;
    int result = s.search(0, sorted_array);
    ASSERT_EQ(3, result);
}
