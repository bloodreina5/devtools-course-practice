// Copyright 2022 Kim Nikita
#include "include/app.h"

#include <string>
#include <vector>

std::string LongerApp::operator()(int argc, const char** argv) {
  if (argc == 1) {
    return help();
  }
  if (!check_args(argc, argv)) {
    return "Given array must contains only integers";
  }
  std::string output;
  std::vector<int> input;
  std::vector<int> result;
  Longer longer;
  for (int i = 1; i < argc; i++) {
    std::string cur(argv[i]);
    input.push_back(std::stoi(cur));
  }
  result = longer.longestIncreasingSubsequence(input);
  int size = result.size();
  for (int i = 0; i < size - 1; i++) {
    output += std::to_string(result[i]);
    output += ' ';
  }
  output += std::to_string(result[size - 1]);
  return output;
}

bool LongerApp::check_args(int argc, const char** argv) {
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j] != '\0'; j++) {
      if (!isdigit(argv[i][j])) {
        return false;
      }
    }
  }
  return true;
}

std::string LongerApp::help() {
  return "The application searches for the longest"
         " increasing subsequence of a given array";
}
