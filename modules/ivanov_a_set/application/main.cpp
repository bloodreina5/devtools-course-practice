// Copyright 2022 Burdukov Mikhail
#include <cstdlib>
#include <iostream>

#include "include/api.h"

int main(int argc, char* argv[]) {
  set_api_t set;
  int i = 1;
  while (i < argc) {
    int mode = std::atoi(argv[i++]);
    if (mode == 0) break;
    if (mode == 3) {
      std::cout << set.size() << "\n";
      continue;
    }
    int val = std::atoi(argv[i++]);
    if (mode == 1) {
      set.insert(val);
    } else {
      set.erase(val);
    }
  }
}
