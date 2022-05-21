// Copyright 2022 Andrich Maria

#ifndef MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_
#define MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_

#include <string.h>

class Sort {
 public:
int op_preced(char c);
bool op_left_assoc(char c);
unsigned int op_arg_count(char c);
bool shunting_yard(char* input, char* output);
};

#endif  //  MODULES_ANDRICH_MARIA_SORT_FACILITY_INCLUDE_SORTFACILITY_H_
