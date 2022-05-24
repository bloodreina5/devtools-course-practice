// Copyright 2022 Lakhov Kirill

#include "include/stohastic_variable.h"
#include <vector>
#include <string>
#include <stdexcept>

StohasticVariable::StohasticVariable(const std::vector<double>& values,
                                     const std::vector<double>& probabilities)
                             : values_(values), probabilities_(probabilities) {}

const std::vector<double>& StohasticVariable::values() {
    return this->values_;
}

const std::vector<double>& StohasticVariable::probabilities() {
    return this->probabilities_;
}

double StohasticVariable::RawMoment(int k) {
    double result = 0;
    int size = this->values_.size();
    for (int i = 0; i < size; i++) {
        result += std::pow(this->values_[i], k) * this->probabilities_[i];
    }
    return result;
}

double StohasticVariable::Mean() {
    int size = this->values_.size();
    for (int i = 0; i < size; i++) {
        if (this->probabilities_[i] < 0) {
            throw std::invalid_argument("Incorrect data");
        }
    }
    return this->RawMoment(1);
}

double StohasticVariable::CentralMoment(int k) {
    double mean = this->Mean();
    double result = 0;
    int size = this->values_.size();
    for (int i = 0; i < size; i++) {
        result += std::pow((this->values_[i] - mean), k)
                  * this->probabilities_[i];
    }
    return result;
}

double StohasticVariable::Dispersion() {
    return this->CentralMoment(2);
}
