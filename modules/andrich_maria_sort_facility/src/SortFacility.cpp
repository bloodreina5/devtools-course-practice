// Copyright 2022 Andrich Maria

#define is_operator(nb1)(nb1 == '+' || nb1 == '-' || nb1 == '/' || \
  nb1 == '*' || nb1 == '!' || nb1 == '%' || nb1 == '=')
#define is_function(nb1)(nb1 >= 'A' && nb1 <= 'Z')
#define is_ident(nb1)((nb1 >= '0' && nb1 <= '9') || (nb1 >= 'a' && nb1 <= 'z'))

#include <string>
#include "include/SortFacility.h"

int Sort::op_preced(const char c) {
    switch (c) {
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

bool Sort::op_left_assoc(const char c) {
    switch (c) {
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

bool Sort::shunting_yard(const char * input, char * output) {
  const char * strpos = input,
    * strend = input + strlen(input);
  char stack[32], sc, * outpos = output;
  unsigned int sl = 0;
  while (strpos < strend) {
    char nb1 = * strpos;
    if (nb1 != ' ') {
      if (is_ident(nb1)) {
        * outpos = nb1;
        ++outpos;
      } else if (is_function(nb1)) {
        stack[sl] = nb1;
        ++sl;
      } else if (nb1 == ',') {
        bool pe = false;
        while (sl > 0) {
          sc = stack[sl - 1];
          if (sc == '(') {
            pe = true;
            break;
          } else {
            * outpos = sc;
            ++outpos;
            sl--;
          }
        }
        if (!pe) {
          throw("Error: separator or parentheses mismatched\n");
          return false;
        }
      } else if (is_operator(nb1)) {
        while (sl > 0) {
          sc = stack[sl - 1];
          if (is_operator(sc) &&
            ((op_left_assoc(nb1) &&
                (op_preced(nb1) <= op_preced(sc))) ||
              (!op_left_assoc(nb1) &&
                (op_preced(nb1) < op_preced(sc))))) {
            * outpos = sc;
            ++outpos;
            sl--;
          } else {
            break;
          }
        }
        stack[sl] = nb1;
        ++sl;
      } else if (nb1 == '(') {
        stack[sl] = nb1;
        ++sl;
      } else if (nb1 == ')') {
        bool pe = false;

        while (sl > 0) {
          sc = stack[sl - 1];
          if (sc == '(') {
            pe = true;
            break;
          } else {
            * outpos = sc;
            ++outpos;
            sl--;
          }
        }
        if (!pe) {
          throw("Error: parentheses mismatched\n");
          return false;
        }
        sl--;
        if (sl > 0) {
          sc = stack[sl - 1];
          if (is_function(sc)) {
            * outpos = sc;
            ++outpos;
            sl--;
          }
        }
      } else {
        throw("Unknown token\n");
        return false;
      }
    }
    ++strpos;
  }

  while (sl > 0) {
    sc = stack[sl - 1];
    if (sc == '(' || sc == ')') {
      throw("Error: parentheses mismatched\n");
      return false;
    }
    * outpos = sc;
    ++outpos;
    --sl;
  }
  * outpos = 0;
  return true;
}
