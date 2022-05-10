// Copyright 2022 Shelepin Nikita

#include "include/simpson.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>

SimpsonSolver::SimpsonSolver() {
  dim = 1;
  f = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };
  limits = {{1, 2}};
  n = {1};
}

SimpsonSolver::SimpsonSolver(const int dim,
                             const function<double(vector<double>)> f,
                             const vector<pair<double, double>> limits,
                             const vector<int> n) {
  this->dim = dim;
  this->f = f;
  this->limits = limits;
  this->n = n;
}

SimpsonSolver::SimpsonSolver(const SimpsonSolver& other) {
  this->dim = other.dim;
  this->f = other.f;
  this->limits = other.limits;
  this->n = other.n;
}

SimpsonSolver& SimpsonSolver::operator=(const SimpsonSolver& other) {
  if (this == &other) return *this;

  this->dim = other.dim;
  this->f = other.f;
  this->limits = other.limits;
  this->n = other.n;
  return *this;
}

function<double(vector<double>)> SimpsonSolver::getFunction() const {
  return this->f;
}

vector<pair<double, double>> SimpsonSolver::getLimits() const {
  return this->limits;
}

vector<int> SimpsonSolver::getN() const { return this->n; }

int SimpsonSolver::getDim() const { return this->dim; }

void SimpsonSolver::setFunction(const function<double(vector<double>)> f) {
  this->f = f;
}

void SimpsonSolver::setLimits(const vector<pair<double, double>> limits) {
  this->limits = limits;
}

void SimpsonSolver::setN(vector<int> n) { this->n = n; }

void SimpsonSolver::setDim(int dim) { this->dim = dim; }

double SimpsonSolver::solve() {
  std::vector<double> h(dim);
  int64_t counter = 1;
  for (int i = 0; i < dim; ++i) {
    h[i] = (limits[i].second - limits[i].first) / n[i];
    counter *= n[i];
  }
  double result = 0.0;
  for (int i = 0; i < counter; ++i) {
    std::vector<std::vector<double>> params(dim);
    int temp = i;
    for (int j = 0; j < dim; ++j) {
      params[j].push_back(limits[j].first + temp % n[j] * h[j]);
      params[j].push_back(limits[j].first + temp % n[j] * h[j] + h[j] / 2);
      params[j].push_back(limits[j].first + temp % n[j] * h[j] + h[j] / 2);
      params[j].push_back(limits[j].first + temp % n[j] * h[j] + h[j] / 2);
      params[j].push_back(limits[j].first + temp % n[j] * h[j] + h[j] / 2);
      params[j].push_back(limits[j].first + temp % n[j] * h[j] + h[j]);
      temp /= n[j];
    }
    std::vector<double> point;
    for (int i = 0; i < pow(6, dim); ++i) {
      int temp = i;
      for (int j = 0; j < dim; ++j) {
        point.push_back(params[j][temp % 6]);
        temp /= 6;
      }
      result += f(point);
      point.clear();
    }
    params.clear();
  }
  for (int i = 0; i < dim; ++i) {
    result *= h[i] / 6.0;
  }
  return result;
}
