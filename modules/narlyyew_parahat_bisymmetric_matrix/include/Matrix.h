// Copyright 2022 Narlyyew Parahat

#ifndef  MODULES_NARLYYEW_PARAHAT_BISYMMETRIC_MATRIX_INCLUDE_MATRIX_H_
#define  MODULES_NARLYYEW_PARAHAT_BISYMMETRIC_MATRIX_INCLUDE_MATRIX_H_

#include "Vector.h"

class Matrix {
 private:
    int n;
    Vector* M;

 public:
    explicit Matrix(int size = 1);
    Matrix(const Matrix& x);
    ~Matrix(void);

    int GetSize();
    void Insert(const int row, const int col, const int element);
    int GetElem(int row, int col);

    Matrix& operator =(const Matrix& x);
    Matrix operator +(const Matrix& x) const;
    Matrix operator -(const Matrix& x) const;
    Matrix operator *(int t) const;
};

#endif  //  MODULES_NARLYYEW_PARAHAT_BISYMMETRIC_MATRIX_INCLUDE_MATRIX_H_
