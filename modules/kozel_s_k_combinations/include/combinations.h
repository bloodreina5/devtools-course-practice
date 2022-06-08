// Copyright 2022 Kozel Svetlana

#ifndef MODULES_KOZEL_S_K_COMBINATIONS_INCLUDE_COMBINATIONS_H_
#define MODULES_KOZEL_S_K_COMBINATIONS_INCLUDE_COMBINATIONS_H_

#include <vector>
#include <stdexcept>

class combinations {
    int n;
    int m;
    std::vector<int> vec;
 public:
    combinations();
    combinations(int n, int m);
    bool next_set();
    int get_cnm();
    ~combinations();
};

#endif  // MODULES_KOZEL_S_K_COMBINATIONS_INCLUDE_COMBINATIONS_H_
