// Copyright 2022 Andrich Maria

#define is_operator(c1)(c1 == '+' || c1 == '-' || c1 == '/' || \
  c1 == '*' || c1 == '!' || c1 == '%' || c1 == '=')
#define is_function(c1)(c1 >= 'A' && c1 <= 'Z')
#define is_ident(c1)((c1 >= '0' && c1 <= '9') || (c1 >= 'a' && c1 <= 'z'))

#include <string>

#include "../include/SortFacility.h"

int Sort::op_preced(const char c1) {
  switch (c1) {
  case '!':
    return 4;
  case '*':
  case '/':
  case '%':
    return 3;
  case '+':
  case '-':
    return 2;
  case '=':
    return 1;
  }
  return 0;
}

bool Sort::op_left_assoc(const char c1) {
  switch (c1) {
  case '*':
  case '/':
  case '%':
  case '+':
  case '-':
  case '=':
    return true;
  case '!':
    return false;
  }
  return false;
}

