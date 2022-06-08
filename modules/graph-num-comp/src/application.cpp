// Copyright 2022 Melnikov Aleksei

#include <string>
#include <vector>
#include <iostream>
#include "include/application.h"
#include "include/num_comp.h"

NumCompApp::NumCompApp() : message_("") {}

void NumCompApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is an application to count the number of " +
    "connectivity components in graph.\n\n" +

    "You can input your own graph or get random graph your size:\n" +
    "To create own graph, please, use the folowwing format: " +
    "$" + appname + " <number of vertexes> <first row> " +
    "<second row> ... <last row> \n" +
    "Example: $" + appname + " 3 110 001 010\n" +
    "Will be created graph with next adjacency list:\n" +
    "1 1 0\n" +
    "0 0 1\n" +
    "0 1 0\n";
}

bool NumCompApp::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (std::stoi(argv[1]) == (argc - 2)) {
    return true;
  }
  help(argv[0], "ERROR: Unvaleble count of parameters.\n\n");
  return false;
}

std::string NumCompApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  int N, edge, comp = 0;
  N = std::stoi(argv[1]);
  std::vector<std::vector<int>> G(N, std::vector<int>(N));
  for (int i = 0; i < argc - 2; i++) {
    for (int j = 0; j < std::stoi(argv[1]); j++) {
      edge = static_cast<int>(argv[i + 2][j]) - 48;
      if (edge != 0 && edge != 1) {
        help(argv[0], "Values can be 1 or 0 only!.\n\n");
        return message_;
      }
      G[i][j] = edge;  // get int from char
    }
  }
  matrixType graph(N, G);
  comp = graph.numComp(5);
  message_ = "The number of connectivity components is " + std::to_string(comp);
  return message_;
}
