// Copyright 2022 Elanskiy Alexandr
#include <gtest/gtest.h>
#include <utility>

#include "include/Euler_function.h"

int EulerFunction::Calculate(int number) {
    int result = number;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            while (number % i == 0) {
                number /= i;
            }
            result -= result / i;
        }
    }
    if (number > 1) {
        result -= result / number;
    }
    return result;
}
