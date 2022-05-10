// Copyright 2022 Oskin Georgii

#ifndef MODULES_OSKIN_G_EQUATION_INCLUDE_EQUATION_H_
#define MODULES_OSKIN_G_EQUATION_INCLUDE_EQUATION_H_

class Equation {
 private:
    double a, b, c;
 public:
    Equation();
    Equation(double a, double b, double c);
    static void SolveEQ(Equation eq, double res[2]);

    double getA() {
        return a;
    }
    double getB() {
        return b;
    }
    double getC() {
        return c;
    }
};

#endif  // MODULES_OSKIN_G_EQUATION_INCLUDE_EQUATION_H_
