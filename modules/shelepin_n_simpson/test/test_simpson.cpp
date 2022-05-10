// Copyright 2022 Shelepin Nikita

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>

#include "include/simpson.h"

TEST(Shelepin_Nikita_SimpsonSolverTest, DefaultConstructor) {
  ASSERT_NO_THROW(SimpsonSolver());
}

TEST(Shelepin_Nikita_SimpsonSolverTest, Getters) {
  ASSERT_NO_THROW(SimpsonSolver());

  SimpsonSolver a;
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  ASSERT_EQ(a.getDim(), 1);
  ASSERT_EQ(a.getN(), test_n);
  ASSERT_EQ(a.getLimits(), test_limits);
  ASSERT_EQ(a.getFunction()({100}), test_func({100}));
}

TEST(Shelepin_Nikita_SimpsonSolverTest, ParamConstructor) {
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  SimpsonSolver a(1, test_func, test_limits, test_n);

  ASSERT_EQ(a.getDim(), 1);
  ASSERT_EQ(a.getN(), test_n);
  ASSERT_EQ(a.getLimits(), test_limits);
  ASSERT_EQ(a.getFunction()({100}), test_func({100}));
}

TEST(Shelepin_Nikita_SimpsonSolverTest, CopyConstructor) {
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  SimpsonSolver a(1, test_func, test_limits, test_n);
  SimpsonSolver b(a);

  ASSERT_EQ(b.getDim(), 1);
  ASSERT_EQ(b.getN(), test_n);
  ASSERT_EQ(b.getLimits(), test_limits);
  ASSERT_EQ(b.getFunction()({100}), test_func({100}));
}

TEST(Shelepin_Nikita_SimpsonSolverTest, CopyAssignment) {
  vector<int> test_n = {1};
  vector<pair<double, double>> test_limits = {{1, 2}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    return x;
  };

  SimpsonSolver a(1, test_func, test_limits, test_n);
  SimpsonSolver b;
  b = a;

  ASSERT_EQ(b.getDim(), 1);
  ASSERT_EQ(b.getN(), test_n);
  ASSERT_EQ(b.getLimits(), test_limits);
  ASSERT_EQ(b.getFunction()({100}), test_func({100}));
}

TEST(Shelepin_Nikita_SimpsonSolverTest, Setters) {
  SimpsonSolver a;

  int test_dim = 2;
  vector<int> test_n = {2, 2};
  vector<pair<double, double>> test_limits = {{1, 2}, {3, 4}};
  function<double(vector<double>)> test_func = [](vector<double> vec) {
    double x = vec[0];
    double y = vec[1];
    return x * y;
  };

  a.setDim(test_dim);
  a.setN(test_n);
  a.setLimits(test_limits);
  a.setFunction(test_func);

  ASSERT_EQ(a.getDim(), test_dim);
  ASSERT_EQ(a.getN(), test_n);
  ASSERT_EQ(a.getLimits(), test_limits);
  ASSERT_EQ(a.getFunction()({2, 3}), test_func({2, 3}));
}

TEST(Shelepin_Nikita_SimpsonSolverTest, Solve1) {
  printf("----- f(x,y) = x * x - 2 * y\n");

  int dim = 2;

  const std::function<double(std::vector<double>)> f =
      [](std::vector<double> vec) {
        double x = vec[0];
        double y = vec[1];
        return x * x - 2 * y;
      };

  std::vector<std::pair<double, double>> limits({{4, 10}, {1, 2}});
  std::vector<int> n({10, 10});

  SimpsonSolver solver(dim, f, limits, n);

  ASSERT_NO_THROW(solver.solve());

  double result = solver.solve();
  printf("----- %f\n", result);
}

TEST(Shelepin_Nikita_SimpsonSolverTest, Solve2) {
  printf("----- f(x,y) = log10(2 * x * x) + 5 * y\n");

  int dim = 2;

  const std::function<double(std::vector<double>)> f =
      [](std::vector<double> vec) {
        double x = vec[0];
        double y = vec[1];
        return log10(2 * x * x) + 5 * y;
      };

  std::vector<std::pair<double, double>> limits({{4, 10}, {1, 2}});
  std::vector<int> n({10, 10});

  SimpsonSolver solver(dim, f, limits, n);

  ASSERT_NO_THROW(solver.solve());

  double result = solver.solve();
  printf("----- %f\n", result);
}

TEST(Shelepin_Nikita_SimpsonSolverTest, Solve3) {
  printf("----- f(x,y) = log10(2 * x * x) + 5 * y\n");

  int dim = 3;

  const std::function<double(std::vector<double>)> f =
      [](std::vector<double> vec) {
        double x = vec[0];
        double y = vec[1];
        double z = vec[2];
        return x * y * z;
      };

  std::vector<std::pair<double, double>> limits({{4, 10}, {1, 2}, {4, 5}});
  std::vector<int> n({3, 2, 2});

  SimpsonSolver solver(dim, f, limits, n);

  ASSERT_NO_THROW(solver.solve());

  double result = solver.solve();
  printf("----- %f\n", result);
}
