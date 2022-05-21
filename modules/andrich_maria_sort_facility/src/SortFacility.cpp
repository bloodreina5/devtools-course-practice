// Copyright 2022 Andrich Maria

#define is_operator(c) (c == '+' || c == '-' || c == '/' || \
c == '*' || c == '!' || c == '%' || c == '=')
#define is_function(c) (c >= 'A' && c <= 'Z')
#define is_ident(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))

#include <string>
#include "include/SortFacility.h"

int Sort::op_preced(char c) {
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

bool Sort::op_left_assoc(char c) {
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

unsigned int Sort::op_arg_count(char c) {
    switch (c) {
    case '*':
    case '/':
    case '%':
    case '+':
    case '-':
    case '=':
        return 2;
    case '!':
        return 1;
    default:
        return c - 'A';
    }
    return 0;
}

bool Sort::shunting_yard(char* input, char* output) {
    const char* strpos = input, * strend = input + strlen(input);
    char c, stack[32], sc, * outpos = output;
    unsigned int sl = 0;
    while (strpos < strend) {
        c = *strpos;
        if (c != ' ') {
            if (is_ident(c)) {
                *outpos = c; ++outpos;
            } else if (is_function(c)) {
                stack[sl] = c;
                ++sl;
            } else if (c == ',') {
                bool pe = false;
                while (sl > 0) {
                    sc = stack[sl - 1];
                    if (sc == '(') {
                        pe = true;
                        break;
                    } else {
                        *outpos = sc; ++outpos;
                        sl--;
                    }
                }
                if (!pe) {
                    throw("Error: separator or parentheses mismatched\n");
                    return false;
                }
            } else if (is_operator(c)) {
                while (sl > 0) {
                    sc = stack[sl - 1];
                    if (is_operator(sc) &&
                        ((op_left_assoc(c)
                            && (op_preced(c) <= op_preced(sc))) ||
                            (!op_left_assoc(c)
                                && (op_preced(c) < op_preced(sc))))) {
                        *outpos = sc; ++outpos;
                        sl--;
                    } else {
                        break;
                    }
                }
                stack[sl] = c;
                ++sl;
            } else if (c == '(') {
                stack[sl] = c;
                ++sl;
            } else if (c == ')') {
                bool pe = false;

                while (sl > 0) {
                    sc = stack[sl - 1];
                    if (sc == '(') {
                        pe = true;
                        break;
                    } else {
                        *outpos = sc; ++outpos;
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
                        *outpos = sc; ++outpos;
                        sl--;
                    }
                }
            } else {
                throw("Unknown token %c\n", c);
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
        *outpos = sc; ++outpos;
        --sl;
    }
    *outpos = 0;
    return true;
}
