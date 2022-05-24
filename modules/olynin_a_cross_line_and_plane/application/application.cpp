// Copyright 2022 Miheev Ivan

#include <iostream>
#include <string>

#include "include/cross_line_and_plane_app.h"

int main(int argc, const char** argv) {
  CLPApplication app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
