// Copyright 2022 Andrich Maria

#ifndef MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_
#define MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_

#include <string.h>

class Sort {
 public:
  bool shunting_yard(const char * input, char * output);
 private :
  int op_preced(const char c);
  bool op_left_assoc(const char c);
};

#endif  //  MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_

