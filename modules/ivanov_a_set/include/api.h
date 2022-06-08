// Copyright 2022 Burdukov Mikhail
#ifndef MODULES_IVANOV_A_SET_INCLUDE_API_H_
#define MODULES_IVANOV_A_SET_INCLUDE_API_H_

#include <vector>
#include "include/ivanov_a_set.h"

class set_api_t {
 private:
  Set set;

 public:
  set_api_t() {}
  explicit set_api_t(const std::vector<int>& c) : set(c) {}
  void insert(const int val) { set.add(val); }
  void erase(const int val) { set.removeValue(val); }
  size_t size() { return set.getSize(); }
};
#endif  // MODULES_IVANOV_A_SET_INCLUDE_API_H_
