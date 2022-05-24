// Copyright 2022 Borisov Maxim

#include "include/triangle_app.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "include/ermakov_pavel_tringle_params.h"

std::string application::operator()(int argc, char** argv) {
  float result = -1.f;
  if (argc == 1) {
    return help(argv[0]);
  }
  if (argc < 5) {
    return "Error: too few arguments";
  }
  if (argc > 6) {
    return "Error: too many arguments";
  }
  arguments args;
  if (validate(argv[0])) args = parse_args(argc, argv);
  _Triangle triangle(args.a, args.b, args.c);
  if (args.operation == "perimeter") result = triangle.get_perimetr();
  if (args.operation == "square") result = triangle.get_square();
  if (args.operation == "height") result = triangle.get_height(args.side);
  return std::to_string(result);
}

std::string application::help(const std::string& appname) {
  return "This is an application to demonstrate coordinates of the vertices of "
         "and calculation of the main parameters of a triangle"
         "the triangle\n Format for arguments:\n" +
         appname +
         "(x1,y1) (x2,y2) (x3,y3) <operation> <side for height "
         "operation>\n Where <operation> is:\n1. "
         "perimeter\n2. "
         "square\n3. height (second argument for height is 1, 2 or 3";
}

bool application::validate(const std::string& str) { return true; }

application::arguments application::parse_args(int argc, char** argv) {
  arguments args;
  for (int i = 1; i <= 3; i++) {
    std::string dot = argv[i];
    auto delimeter = dot.find(",");
    float f = std::stof(dot.substr(0, delimeter));
    float s = std::stof(dot.substr(delimeter + 1));
    if (i == 1) args.a = {f, s};
    if (i == 2) args.b = {f, s};
    if (i == 3) args.c = {f, s};
  }
  args.operation = argv[4];
  if (argc > 5) args.side = std::stoi(argv[5]);
  return args;
}
