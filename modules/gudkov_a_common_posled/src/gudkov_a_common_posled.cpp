// Copyright 2022 Gudkov Andrey

#include <algorithm>
#include <string>
#include <vector>
#include "include/gudkov_a_common_posled.h"

int _common_seq ::find_common_seq(const std::string& first,
    const std::string& second) {
    int first_size = first.size();
    int second_size = second.size();
    if (first_size == 0 || second_size == 0) {
        return 0;
    }
    std::vector<std::vector<char>> _F(first_size + 1,
        std::vector<char>(second_size + 1, 0));
    for (int i = 1; i <= first_size; i++) {
        for (int j = 1; j <= second_size; j++) {
            if (first[i - 1] == second[j - 1]) {
                _F[i][j] = _F[i - 1][j - 1] + 1;
            } else {
                _F[i][j] = std::max(_F[i - 1][j], _F[i][j - 1]);
            }
        }
    }
    return _F[first_size][second_size];
}
