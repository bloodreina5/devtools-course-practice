// Copyright 2022 Shelepin Nikita

#include "include/bisymmetric_matrix.h"

#include <gtest/gtest.h>

#include <random>
#include <vector>

// using std::vector;

bool BisymmetricMatrix::isSymmetric(vector<vector<double>> mat) {
  int N = static_cast<int>(mat.size());

  vector<vector<double>> temp(mat);
  transpose(&temp);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (mat[i][j] != temp[i][j]) return false;
  return true;
}

BisymmetricMatrix::BisymmetricMatrix() {
  this->container = vector<vector<double>>();
  this->size = 0;
}

BisymmetricMatrix::BisymmetricMatrix(const BisymmetricMatrix& other) {
  this->container = other.container;
  this->size = other.size;
}

BisymmetricMatrix::BisymmetricMatrix(const vector<vector<double>>& other) {
  if (!isSymmetric(other)) {
    throw -1;
  }

  this->container = other;
  this->size = other.size();
}

BisymmetricMatrix::BisymmetricMatrix(int n) {
  this->container = vector<vector<double>>(n, vector<double>(n, 0));
  this->size = n;
}

BisymmetricMatrix& BisymmetricMatrix::operator=(
    const BisymmetricMatrix& other) {
  if (this == &other) return *this;

  this->container = other.container;
  this->size = other.size;
  return *this;
}

BisymmetricMatrix& BisymmetricMatrix::operator+(
    const BisymmetricMatrix& other) {
  if (this->size != other.size) {
    throw -1;
  }

  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      (*this)[i][j] = (*this)[i][j] + other[i][j];
      (*this)[j][i] = (*this)[i][j];
    }
  }

  return *this;
}

BisymmetricMatrix& BisymmetricMatrix::operator-(
    const BisymmetricMatrix& other) {
  if (this->size != other.size) {
    throw -1;
  }

  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      (*this)[i][j] = (*this)[i][j] - other[i][j];
      (*this)[j][i] = (*this)[i][j];
    }
  }

  return *this;
}

BisymmetricMatrix& BisymmetricMatrix::operator*(
    const BisymmetricMatrix& other) {
  if (this->size != other.size) {
    throw -1;
  }

  BisymmetricMatrix temp(size);

  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      for (int k = 0; k < size; k++) {
        temp[i][j] += (*this)[i][k] * other[k][j];
      }

      temp[j][i] = temp[i][j];
    }
  }

  (*this) = temp;
  return *this;
}

BisymmetricMatrix& BisymmetricMatrix::operator/(
    const BisymmetricMatrix& other) {
  if (this->size != other.size) {
    throw -1;
  }

  BisymmetricMatrix temp(size);

  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      for (int k = 0; k < size; k++) {
        temp[i][j] += (*this)[i][k] / other[k][j];
      }

      temp[j][i] = temp[i][j];
    }
  }

  (*this) = temp;
  return *this;
}

void BisymmetricMatrix::fillWithRand(int n) {
  (*this) = BisymmetricMatrix(n);

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<double> distribution(0, 100);

  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; j++) {
      container[i][j] = distribution(generator);
      container[j][i] = container[i][j];
    }
}

void BisymmetricMatrix::transpose(vector<vector<double>>* mat) {
  vector<vector<double>> temp(*mat);
  int size = mat->size();
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) temp[i][j] = (*mat)[j][i];
  (*mat) = temp;
}
