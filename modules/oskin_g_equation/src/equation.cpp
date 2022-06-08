// Copyright 2022 Oskin Georgii

#include "include/equation.h"
#include <math.h>
#include<string>
#include <iostream>
Equation::Equation() {
    a = 2;
    b = 1;
    c = -3;
}
Equation::Equation(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
    if ((b != 0) && (c != 0)) {
        if ((b * b - 4 * a * c) < 0) {
            throw std::string("Equation does not have roots in R");  // ddd
        }
    }
}

void Equation::SolveEQ(Equation eq, double res[2]) {
    double a = eq.getA();
    double b = eq.getB();
    double c = eq.getC();

    double dis = ((b * b) - (4 * a * c));
    double sq_dis = sqrt(dis);
    if (b == 0) {
        res[0] = sqrt(-c / a);
        res[1] = -res[0];
    }
    if (c == 0) {
        res[0] = 0;
        res[1] = -b / a;
    }
    if ((a && b && c) != 0) {
        res[0] = (-b + sq_dis) / (2 * a);
        res[1] = (-b - sq_dis) / (2 * a);
    }
}
