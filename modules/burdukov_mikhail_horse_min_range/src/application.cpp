// Copyright 2022 Melnikov Aleksei

#include <string>
#include <vector>
#include <iostream>
#include "include/application.h"
#include "include/horse_min_range.h"

HorseMinRangeApp::HorseMinRangeApp() : message_("") {}

void HorseMinRangeApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is an application to count steps by chess horse\n\n" +

    "You can input horse location on chessboard and the finish point\n" +
    "Also you can add barries:"
    "To start programm, please, use the folowwing format: " +
    "$" + appname + " <number of vertexes> <first row> " +
    "<start point> <finish point> <barrier1> ... <barrierN>\n";
}

bool HorseMinRangeApp::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) help(argv[0]);
  else if (argc > 2) return true;
  else
    help(argv[0], "ERROR: Unvaleble count of parameters.\n\n");
  return false;
}

std::string HorseMinRangeApp::operator()(int argc, const char** argv) {
  int steps;
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  if ((argv[1][0] < 'a' || argv[1][0] > 'h') ||
    (argv[2][0] < 'a' || argv[2][0] > 'h') ||
    (argv[1][1] < '1' || argv[1][1] > '8') ||
    (argv[2][1] < '1' || argv[2][1] > '8')) {
    help(argv[0], "Points are not valid!\n");
    return message_;
  }
  chess_position_t st(argv[1][0], argv[1][1] - 48);
  chess_position_t fin(argv[2][0], argv[2][1] - 48);
  minHorseRange res;
  res.set_start(st);
  res.set_finish(fin);
  if (argc > 3) {
    for (int i = 3; i < argc; i++) {
      if ((argv[i][0] < 'a' || argv[i][0] > 'h') ||
        (argv[1][1] < '1' || argv[1][1] > '8')) {
        help(argv[0], "Barriers are not valid!\n");
        return message_;
      }
      res.set_barrier(chess_position_t(argv[i][0], argv[i][1] - 48));
    }
  }
  steps = res.calc_range();
  message_ = "The number of steps: " + std::to_string(steps);
  return message_;
}


