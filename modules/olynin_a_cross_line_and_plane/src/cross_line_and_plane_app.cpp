// Copyright 2022 Miheev Ivan

#include "include/cross_line_and_plane_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "include/cross_line_and_plane.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }

  Space sp;
  Line ln;
  Plane pn;
  int i = 1;

  if (std::string(argv[i]) == "--line" || std::string(argv[i]) == "-l") {
    i += 7;
    if (argc >= i) {
      ln.SetX_1(strtod(argv[2], NULL));
      ln.SetY_1(strtod(argv[3], NULL));
      ln.SetZ_1(strtod(argv[4], NULL));
      ln.SetA_x(strtod(argv[5], NULL));
      ln.SetA_y(strtod(argv[6], NULL));
      ln.SetA_z(strtod(argv[7], NULL));
    }

    if (argc == 2) {
      ln.shwLine();
    }
  }

  if ((argc > i) &&
      (std::string(argv[i]) == "--plane" || std::string(argv[i]) == "-p")) {
    i += 5;
    if (argc >= i) {
      pn.SetA(strtod(argv[2], NULL));
      pn.SetB(strtod(argv[3], NULL));
      pn.SetC(strtod(argv[4], NULL));
      pn.SetD(strtod(argv[5], NULL));
    }

    if (argc == 2) {
      pn.shwPlane();
    }
  }

  if (std::string(argv[argc - 1]) == "-r" ||
      std::string(argv[argc - 1]) == "--relation") {
    os << sp.Relationship(ln, pn);
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[argc - 1]) == "-i" ||
      std::string(argv[argc - 1]) == "--intersection") {
    double x, y, z;
    sp.GetPointOfIntersection(ln, pn, &x, &y, &z);
    os << x << " " << y << " " << z;
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[argc - 1]) == "-per" ||
      std::string(argv[argc - 1]) == "--perpendicular") {
    os << sp.IsPerpendicular(ln, pn);
    std::cout << os.str() << std::endl;
    return "success";
  }

  return "success";
}

std::string CLPApplication::help() {
  std::string help =
      "This program's purpose to calculate if line crosses the plane or not";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
