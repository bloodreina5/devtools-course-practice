// Copyright 2022 Vitulin Ivan

#include "include/big_int_application.h"
#include <string>

bool BigIntApplication::readArguments(int argc, const char ** argv) {
    if (argc != 4)
        return false;

    left = BigInt(argv[1]);
    right = BigInt(argv[3]);

    for (size_t i = 0; i < sizeof operators / sizeof operators[0]; ++i) {
        if (operators[i] == argv[2]) {
            operator_ind = i;
            return true;
        }
    }

    return false;
}

std::string BigIntApplication::calculate() {
    BigInt big_int_result;
    switch (operator_ind) {
    case 0:
        big_int_result = left + right;
        return big_int_result.BigIntToString();

    case 1:
        big_int_result = left - right;
        return big_int_result.BigIntToString();

    case 2:
        big_int_result = left * right;
        return big_int_result.BigIntToString();

    case 3:
        big_int_result = left / right;
        return big_int_result.BigIntToString();

    case 4:
        big_int_result = left % right;
        return big_int_result.BigIntToString();
    }

    bool bool_result;
    switch (operator_ind) {
    case 5:
        bool_result = left > right;
        break;

    case 6:
        bool_result = left >= right;
        break;

    case 7:
        bool_result = left < right;
        break;

    case 8:
        bool_result = left <= right;
        break;

    case 9:
        bool_result = left == right;
        break;

    case 10:
        bool_result = left != right;
        break;
    }

    if (bool_result)
        return "It`s true!";
    else
        return "It`s false!";
}

std::string BigIntApplication::operator()(int argc, const char ** argv) {
    if (!readArguments(argc, argv))
         return "Input error! \n"
                 "Enter an expression with two numbers. Example: 22 * 6.\n"
                 "Supported operations: + - * / % > >= < <= == !=";

    return calculate();
}
