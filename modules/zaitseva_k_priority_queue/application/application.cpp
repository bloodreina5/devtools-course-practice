// Copyright 2022 Kuklin Andrey

#include <iostream>
#include <string>

#include "include/priority_queue_app.h"

int main(int argc, const char** argv) {
  PriorityQueueApplication app;
  std::string output = app(argc, argv);
  std::cout << output;
  return 0;
}
