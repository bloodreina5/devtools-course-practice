// Copyright 2022 Remizova Antonina

#ifndef MODULES_REMIZOVA_MATRIX_INCLUDE_REMIZOVA_A_MATRIX_H_
#define MODULES_REMIZOVA_MATRIX_INCLUDE_REMIZOVA_A_MATRIX_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

template <class T>
class TMatrix {
    int rows;
    int cols;
    std::vector<std::vector<T> > mtr;

 public:
    TMatrix(int _rows, int _cols);
    TMatrix(int _rows, int _cols, T num);
    TMatrix(const TMatrix<T>& m);
    ~TMatrix();

    bool operator == (const TMatrix<T>& m) const;
    bool operator != (const TMatrix<T>& m) const;
    TMatrix<T>& operator = (const TMatrix<T>& m);
    TMatrix<T> operator + (const TMatrix<T>& m);
    TMatrix<T> operator - (const TMatrix<T>& m);
    TMatrix<T> operator * (const TMatrix<T>& m);

    void setMatrix(const std::vector<std::vector<T>>& vec);
    std::vector<std::vector<T>> getMatrix();
    TMatrix<T> matrixWithoutRowAndCol(int delRow, int delCol);
    int determinant(TMatrix<T> m) const;
    TMatrix<T> transposition() const;
    TMatrix<T> alliance() const;
    TMatrix<T> reverse() const;
};

template <class T>
TMatrix<T>::TMatrix(int _rows, int _cols)
    : rows(_rows), cols(_cols), mtr(_rows, std::vector<T>(_cols)) {
    if (_rows < 0)
        throw "number of cols is less than 0";
    if (_cols < 0)
        throw "number of rows is less than 0";
}

template <class T>
TMatrix<T>::TMatrix(int _rows, int _cols, T num)
    : rows(_rows), cols(_cols), mtr(_rows, std::vector<T>(_cols)) {
    if (_rows < 0)
        throw "number of cols is less than 0";
    if (_cols < 0)
        throw "number of rows is less than 0";
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            mtr[i][j] = num;
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& m)
    : rows(m.rows), cols(m.cols), mtr(m.rows, std::vector<T>(m.cols)) {
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            mtr[i][j] = m.mtr[i][j];
}

template <class T>
TMatrix<T>::~TMatrix() { }

template<class T>
bool TMatrix<T>::operator==(const TMatrix& m) const {
    if (rows != m.rows || cols != m.cols)
        return false;
    for (size_t i = 0; i < mtr.size(); i++) {
        for (size_t j = 0; j < mtr[i].size(); j++) {
            if (mtr[i][j] != m.mtr[i][j])
                return false;
        }
    }
    return true;
}

template<class T>
bool TMatrix<T>::operator!=(const TMatrix& m) const {
    if (rows != m.rows || cols != m.cols)
        return true;
    for (size_t i = 0; i < mtr.size(); i++) {
        for (size_t j = 0; j < mtr[i].size(); j++) {
            if (mtr[i][j] != m.mtr[i][j])
                return true;
        }
    }
    return false;
}

template<class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m) {
    if (this == &m)
        return *this;
    if (rows != m.rows || cols != m.cols) {
        std::vector<std::vector<T>>().swap(mtr);
        mtr.resize(m.rows);
        for (size_t i = 0; i < mtr.size(); i++)
            mtr[i].resize(m.cols);
        rows = m.rows;
        cols = m.cols;
    }
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            mtr[i][j] = m.mtr[i][j];
    return *this;
}

template<class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m) {
    if (rows != m.rows || cols != m.cols)
        throw "matrices are not equal";
    TMatrix tmp(rows, cols);
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            tmp.mtr[i][j] = mtr[i][j] + m.mtr[i][j];
    return tmp;
}

template<class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m) {
    if (rows != m.rows || cols != m.cols)
        throw "matrices are not equal";
    TMatrix tmp(m.rows, m.cols);
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            tmp.mtr[i][j] = mtr[i][j] - m.mtr[i][j];
    return tmp;
}

template<class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m) {
    if (cols != m.rows)
        throw "matrices cannot be multiplied";
    TMatrix tmp(rows, m.cols);
    for (size_t i = 0; i < tmp.mtr.size(); i++)
        for (size_t j = 0; j < tmp.mtr[i].size(); j++) {
            tmp.mtr[i][j] = 0;
            for (size_t k = 0; k < mtr[i].size(); k++)
                tmp.mtr[i][j] += mtr[i][k] * m.mtr[k][j];
        }
    return tmp;
}

template<class T>
void TMatrix<T>::setMatrix(const std::vector<std::vector<T>>& vec) {
    if (vec.size() != mtr.size() || vec[0].size() != mtr[0].size())
        throw "matrix cannot be specified";
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            mtr[i][j] = vec[i][j];
}

template<class T>
std::vector<std::vector<T>> TMatrix<T>::getMatrix() { return mtr; }

template<class T>
TMatrix<T> TMatrix<T>::matrixWithoutRowAndCol(int delRow, int delCol) {
    int offsetRow;
    int offsetCol;
    TMatrix tmp(rows - 1, cols - 1);
    offsetRow = 0;
    for (int i = 0; i < rows - 1; i++) {
        if (i == delRow) {
            offsetRow = 1;
        }
        offsetCol = 0;
        for (int j = 0; j < cols - 1; j++) {
            if (j == delCol) {
                offsetCol = 1;
            }
            tmp.mtr[i][j] = mtr[i + offsetRow][j + offsetCol];
        }
    }
    return tmp;
}

template<class T>
int TMatrix<T>::determinant(TMatrix<T> m) const {
    if (m.cols != m.rows)
        throw "matrix is not square";

    int det = 0;  // determinant
    int degree = 1;  // mult

    if (m.cols == 1)
        return m.mtr[0][0];

    if (m.cols == 2)
        return (m.mtr[0][0] * m.mtr[1][1] - m.mtr[0][1] * m.mtr[1][0]);

    TMatrix tmp(m.rows - 1, m.cols - 1);

    for (size_t j = 0; j < m.mtr.size(); j++) {
        tmp = m.matrixWithoutRowAndCol(0, j);
        det += degree * m.mtr[0][j] * determinant(tmp);
        degree = -degree;
    }

    return det;
}

template<class T>
TMatrix<T> TMatrix<T>::transposition() const {
    TMatrix trans(cols, rows);
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            trans.mtr[j][i] = mtr[i][j];
    return trans;
}

template<class T>
TMatrix<T> TMatrix<T>::alliance() const {
    TMatrix all(rows, cols);
    TMatrix trans(rows, cols);
    trans = transposition();
    TMatrix tmp(rows, cols);
    int fact = -1;

    for (size_t i = 0; i < trans.mtr.size(); i++)
        for (size_t j = 0; j < trans.mtr[i].size(); j++) {
            tmp = trans.matrixWithoutRowAndCol(i, j);
            all.mtr[i][j] = pow(fact, i + j) * tmp.determinant(tmp);
        }

    return all;
}

template<class T>
TMatrix<T> TMatrix<T>::reverse() const {
    if (cols != rows)
        throw "matrix is not square";
    if (determinant(*this) == 0)
        throw "matrix is degenerate";
    TMatrix all = alliance();
    TMatrix rev(rows, cols);
    for (size_t i = 0; i < mtr.size(); i++)
        for (size_t j = 0; j < mtr[i].size(); j++)
            rev.mtr[i][j] = all.mtr[i][j] / determinant(*this);
    return rev;
}



#endif  // MODULES_REMIZOVA_MATRIX_INCLUDE_REMIZOVA_A_MATRIX_H_

