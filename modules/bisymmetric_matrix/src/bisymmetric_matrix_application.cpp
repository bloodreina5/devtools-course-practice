// Copyright 2022 Shelepin Nikita

#include "include/bisymmetric_matrix_application.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/bisymmetric_matrix.h"

BMApplication::BMApplication() {}

std::string BMApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    std::vector<std::vector<double>> test_matrix = { {1, 2}, {2, 1} };
    BisymmetricMatrix a(test_matrix);
    BisymmetricMatrix b;
    b = a + a;

    os << a[0][0];
    std::cout << os.str() << std::endl;
    return "success";
  }

  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    std::vector<std::vector<double>> test_matrix = { {1, 2}, {2, 1} };
    BisymmetricMatrix a(test_matrix);
    BisymmetricMatrix b;
    b = a - a;

    os << a[0][0];
    std::cout << os.str() << std::endl;
    return "success";
  }

  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    std::vector<std::vector<double>> test_matrix = { {1, 2}, {2, 1} };
    BisymmetricMatrix a(test_matrix);
    BisymmetricMatrix b;
    b = a * a;

    os << a[0][0];
    std::cout << os.str() << std::endl;
    return "success";
  }

  if (std::string(argv[i]) == "--test4" || std::string(argv[i]) == "-t4") {
    std::vector<std::vector<double>> test_matrix = { {1, 2}, {2, 1} };
    BisymmetricMatrix a(test_matrix);
    BisymmetricMatrix b;
    b = a / a;

    os << a[0][0];
    std::cout << os.str() << std::endl;
    return "success";
  }

  return "success";
}

std::string BMApplication::help() {
  std::string help = "This program solves bisymmetric matrices";
  return help;
}

std::string BMApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
