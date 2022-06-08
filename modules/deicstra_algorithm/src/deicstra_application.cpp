// Copyright 2022 Zaitseva Ksenia

#include "include/deicstra_application.h"

#include <cmath>
#include <string>
#include <vector>

bool DeicstraApplication::help(int argc, const char* argv[], std::size_t* top,
                               std::vector<std::vector<std::size_t>>* graf) {
  if (argc <= 3) {
    return false;
  }

  std::vector<std::size_t> vector;

  for (int i = 2; i < argc; ++i) {
    if (argv[i][0] == '|') {
      continue;
    } else if (argv[i][0] == ')') {
      *top = atoi(argv[i + 1]);
      break;
    } else {
      vector.push_back(atoi(argv[i]));
    }
  }
  if (sqrt(vector.size()) != static_cast<int>(sqrt(vector.size()))) {
    return false;
  }

  graf->resize(static_cast<int>(sqrt(vector.size())));
  for (std::size_t i = 0; i < graf->size(); i++) {
    for (std::size_t j = 0; j < graf->size(); j++) {
      (*graf)[i].push_back(vector[i * graf->size() + j]);
    }
  }
  if (*top >= 0 && *top < graf->size())
    return checkGraf(*graf);
  else
    return false;
}

bool DeicstraApplication::checkGraf(
    const std::vector<std::vector<std::size_t>>& graf) {
  for (std::size_t i = 0; i < graf.size(); i++) {
    if (graf[i][i] != 0) {
      return false;
    }
    for (std::size_t j = 0; j < graf.size(); j++) {
      if (graf[i][j] != graf[j][i]) {
        return false;
      }
      if (graf[i][j] < 0) return false;
    }
  }
  return true;
}

std::string DeicstraApplication::operator()(int argc, const char* argv[]) {
  std::cout << "This is algorithm Deicstra application.\n"
            << "Please provide arguments in following format:\n"
            << "$ " << argv[0] << " <matrix> <target vertice>\n\n"
            << "Example: " << argv[0] << " (0 2 1 | 2 0 3 | 1 3 0) 0 \n\n";
  std::size_t top;
  std::vector<std::vector<std::size_t>> graf;
  if (!help(argc, argv, &top, &graf)) {
    std::cout << "Incorrect parametrs.\n";
    return std::string();
  }
  Algorithm Deicstra;
  std::vector<std::size_t> res = Deicstra.getDeicstra(graf, top);
  std::string print_result = "Distance between vertices ";
  for (std::size_t i = 0; i < res.size(); i++) {
    print_result +=
        toString(top) + " and " + toString(i) + " is " + toString(res[i]);
    if (i != res.size() - 1) {
      print_result += ", ";
    }
  }
  return print_result;
}
