// Copyright 2022 Belyaev Ilya

#include "include/simpson_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/simpson.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    function<double(vector<double>)> test_func = [](vector<double> vec) {
      double x = vec[0];
      return x;
    };
    vector<int> test_n = {atoi(argv[2])};
    vector<pair<double, double>> test_limits = {{atoi(argv[3]), atoi(argv[4])}};
    SimpsonSolver a(1, test_func, test_limits, test_n);
    os << a.getDim();
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    function<double(vector<double>)> test_func = [](vector<double> vec) {
      double x = vec[0];
      return x;
    };
    vector<int> test_n = {atoi(argv[2])};
    vector<pair<double, double>> test_limits = {{atoi(argv[3]), atoi(argv[4])}};
    SimpsonSolver a(1, test_func, test_limits, test_n);
    os << a.getN()[0];
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    function<double(vector<double>)> test_func = [](vector<double> vec) {
      double x = vec[0];
      return x;
    };
    vector<int> test_n = {atoi(argv[2])};
    vector<pair<double, double>> test_limits = {{atoi(argv[3]), atoi(argv[4])}};
    SimpsonSolver a(1, test_func, test_limits, test_n);
    os << a.getLimits()[0].first;
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test4" || std::string(argv[i]) == "-t4") {
    function<double(vector<double>)> test_func = [](vector<double> vec) {
      double x = vec[0];
      return x;
    };
    vector<int> test_n = {atoi(argv[2])};
    vector<pair<double, double>> test_limits = {{atoi(argv[3]), atoi(argv[4])}};
    SimpsonSolver a(1, test_func, test_limits, test_n);
    os << a.getLimits()[0].second;
    std::cout << os.str() << std::endl;
    return "success";
  }
  return "success";
}

std::string CLPApplication::help() {
  std::string help =
      "This program considers the integral";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
