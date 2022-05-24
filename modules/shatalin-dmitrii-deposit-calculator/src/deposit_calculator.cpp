// Copyright 2022 Shatalin Dmitrii

#include "include/deposit_calculator.h"

double DepositCalculator::calculateDeposit(double amount, int years,
    double percent) {
    if (amount < 0.0 || years < 0 || percent < 0.0) {
        throw std::invalid_argument("Enter the correct parameters!");
    }
    double result = amount;
    result += amount * percent / 100.0 * years;
    return result;
}
