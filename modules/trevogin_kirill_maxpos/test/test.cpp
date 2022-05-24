// Copyright 2022 Trevogin Kirill

#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include <vector>

#include "include/trevogin_kirill_maxpos.h"

TEST(Trevogin_lab2,
  check_func_get_random_vector) {
  int n = 10;
  std::vector<int> vec1, vec2;
  vec1 = Longer::getRandomVector(n);
  vec2 = vec1;

  EXPECT_EQ(Longer::longestIncreasingSubsequence(vec1),
    Longer::longestIncreasingSubsequence(vec2));
}

TEST(Trevogin_lab2,
  check_func_longestIncreasingSubsequence) {
  std::vector<int> vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> vec;
  vec = Longer::longestIncreasingSubsequence(vector);

  EXPECT_EQ(vec, vector);
  EXPECT_EQ(vec.size(), vector.size());
}

TEST(Trevogin_lab2,
  pef_check) {
  std::vector<int> vector = { 4, 3, 4, 6, 7, 4, 9, 7, 8 };
  std::vector<int> vec = { 3, 4, 6, 7 };
  std::vector<int> vec2 = Longer::longestIncreasingSubsequence(vector);
  EXPECT_EQ(vec, vec2);
  EXPECT_EQ(vec.size(), vec2.size());
}

TEST(Trevogin_lab2,
  check_not_increasing) {
  std::vector<int> vector = { 7, 7, 7, 7, 7 };
  std::vector<int> vec = { 7 };
  std::vector<int> vec2 = Longer::longestIncreasingSubsequence(vector);
  EXPECT_EQ(vec, vec2);
  EXPECT_EQ(vec.size(), vec2.size());
}

TEST(Trevogin_lab2,
  check_decreasing) {
  std::vector<int> vector = { 8, 7, 5, 3, 2 };
  std::vector<int> vec = { 8 };
  std::vector<int> vec2 = Longer::longestIncreasingSubsequence(vector);
  EXPECT_EQ(vec, vec2);
  EXPECT_EQ(vec.size(), vec2.size());
}
