// Copyright 2022 Cheremushkin Kirill

#ifndef MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_H_

#include <string>

#include "Monom.h"

class Polynom : public Monom {
 private:
    Monom* StartMonom;
    int SIZE = 1;
    std::string FormattingCoeff(double coef);
    std::string GetSign(double coef);
    Monom CurrentMonom(Monom* p, int id);
 public :
    Polynom();
    explicit Polynom(int size);
    Polynom(const Polynom& polynom);

    void ClearList();
    void SetSize(int size);
    void Equalizer();
    std::string StrPolynom();

    Polynom& operator+(const Monom& monom);
    Polynom& operator-(const Monom& monom);
    Polynom& operator*(const Monom& monom);
    Polynom& operator/(const Monom& monom);

    Polynom& operator=(const Polynom& polynom);
    Polynom operator+(const Polynom& polynom);
    Polynom operator-(const Polynom& polynom);
    Polynom operator*(const Polynom& polynom);
    Polynom operator/(const Polynom& polynom);

    ~Polynom();
    Monom* GetStartMonom();
};
#endif  // MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_H_
