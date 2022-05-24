// Copyright 2022 Trevogin Kirill

#include "include/trevogin_kirill_maxpos.h"
#include <vector>
#include <cstdlib>
#include <ctime>


std::vector<int> Longer::getRandomVector(int n) {
  std::vector<int> vec;
  std::srand(std::time(0));
  vec.resize(n);
  for (int i = 0; i < n; ++i) {
    vec[i] = std::rand() * ((std::rand() % 2 == 0) ? -1 : 1);
  }
  return vec;
}

std::vector<int> Longer::longestIncreasingSubsequence(std::vector<int> vec) {
  int size_of_vec, max, k, num, x;
  std::vector<int> local_vec;
  size_of_vec = vec.size();
  k = max = num = 0;
  for (int i = 0; i < size_of_vec - 1; i++) {
    if (vec[i + 1] > vec[i]) {
      k++;
    } else {
      k = 0;
    }
    if (k > max) {
      max = k;
      num = i + 1;
    }
  }
  max++;
  x = num - max + 1;
  for (int i = x; i < max + x; i++) {
    local_vec.push_back(vec[i]);
  }
  return local_vec;
}
