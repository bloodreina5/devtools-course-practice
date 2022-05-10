// Copyright 2022 Shelepin Nikita

#ifndef MODULES_SHELEPIN_N_SIMPSON_INCLUDE_SIMPSON_H_
#define MODULES_SHELEPIN_N_SIMPSON_INCLUDE_SIMPSON_H_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

using std::function;
using std::pair;
using std::vector;

class SimpsonSolver {
 public:
  SimpsonSolver();
  SimpsonSolver(const int dim, const function<double(vector<double>)> f,
                const vector<pair<double, double>> limits, const vector<int> n);
  SimpsonSolver(const SimpsonSolver& other);

  SimpsonSolver& operator=(const SimpsonSolver& other);

  function<double(vector<double>)> getFunction() const;
  vector<pair<double, double>> getLimits() const;
  vector<int> getN() const;
  int getDim() const;

  void setFunction(const function<double(vector<double>)> f);
  void setLimits(const vector<pair<double, double>> limits);
  void setN(vector<int> n);
  void setDim(int dim);

  double solve();

 private:
  function<double(vector<double>)> f;
  vector<pair<double, double>> limits;
  vector<int> n;

  int dim;
};

#endif  // MODULES_SHELEPIN_N_SIMPSON_INCLUDE_SIMPSON_H_
