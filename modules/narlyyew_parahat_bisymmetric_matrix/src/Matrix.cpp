// Copyright 2022 Narlyyew Parahat

#include "include/Matrix.h"

Matrix::Matrix(int size) {
    n = size;
    M = new Vector[size];

    for (int i = 0; i <= size / 2; i++)
        M[i] = Vector(i + 1, 0);

    for (int i = static_cast<int>(size / 2) + 1; i < size; i++)
        M[i] = Vector(size - i, 0);
}

Matrix::Matrix(const Matrix& x) {
    n = x.n;

    M = new Vector[n];
    for (int i = 0; i < n; i++)
        M[i] = x.M[i];
}

Matrix::~Matrix(void) {
    delete[] M;
}

int Matrix::GetSize() {
    return n;
}

void Matrix::Insert(const int row,
    const int col,
    const int element) {
    if (row <= 0 || row >= n)
        throw "Invalid index in Matrix::Insert.";
    else
        M[row - 1].Insert(col - 1, element);
}

int Matrix::GetElem(int row, int col) {
    if (row <= 0 || col <= 0 || row > n || col > n)
        throw "Invalid index in Matrix::GetElem.";

    if (row >= col) {
        if (row + col <= n + 1)
            return M[row - 1][col - 1];
        else
            return M[n + 1 - col - 1][n + 1 - row];
    } else {
        if (row + col <= n + 1)
            return M[col - 1][row];
        else
            return M[n + 1 - row - 1][n + 1 - col];
    }
}

Matrix& Matrix::operator = (const Matrix& x) {
    if (n != x.n) {
        n = x.n;
        delete[] M;
        M = new Vector[n];
    }

    for (int i = 0; i < n; i++)
        M[i] = x.M[i];

    return *this;
}

Matrix Matrix::operator + (const Matrix& x) const {
    if (n != x.n)
        throw "It is not possible to sum matrices with different sizes.";

    Matrix res(n);

    for (int i = 0; i < n; i++)
        res.M[i] = M[i] + x.M[i];

    return res;
}

Matrix Matrix::operator - (const Matrix& x) const {
    if (n != x.n)
        throw "Size Error";

    Matrix res(n);

    for (int i = 0; i < n; i++)
        res.M[i] = M[i] - x.M[i];

    return res;
}

Matrix Matrix::operator * (const int t) const {
    Matrix res(n);

    for (int i = 0; i < n; i++)
        res.M[i] = M[i] * t;

    return res;
}
