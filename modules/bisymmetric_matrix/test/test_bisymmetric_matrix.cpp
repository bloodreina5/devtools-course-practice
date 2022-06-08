// Copyright 2022 Shelepin Nikita

#include <gtest/gtest.h>

#include <vector>

#include "include/bisymmetric_matrix.h"

TEST(BisymmetricMatrix_Test, DefaultConstructor) {
  ASSERT_NO_THROW(BisymmetricMatrix());
}

TEST(BisymmetricMatrix_Test, Getters) {
  ASSERT_NO_THROW(BisymmetricMatrix());

  int test_size = 5;
  BisymmetricMatrix a(test_size);

  ASSERT_EQ(a.getSize(), test_size);
}

TEST(BisymmetricMatrix_Test, ParamConstructor) {
  int test_size = 5;
  BisymmetricMatrix a(test_size);

  ASSERT_EQ(a.getSize(), test_size);
}

TEST(BisymmetricMatrix_Test, Transpose) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {3, 4}};
  BisymmetricMatrix a;
  a.transpose(&test_matrix);
  ASSERT_EQ(test_matrix[0][0], 1);
  ASSERT_EQ(test_matrix[1][0], 2);
}

TEST(BisymmetricMatrix_Test, ParamConstructor2) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);

  ASSERT_EQ(a.getSize(), test_size);
  ASSERT_EQ(a[0][0], 1);
  ASSERT_EQ(a[1][0], 2);
}

// TEST(BisymmetricMatrix_Test, ParamConstructor_Not_Symmetric) {
//  const std::vector<std::vector<double>> test_matrix1 = { {1, 2}, {3, 4} };
//  ASSERT_ANY_THROW(BisymmetricMatrix(test_matrix1));
//}

TEST(BisymmetricMatrix_Test, CopyConstructor) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);
  BisymmetricMatrix b(a);

  ASSERT_EQ(b.getSize(), test_size);
  ASSERT_EQ(b[0][0], 1);
  ASSERT_EQ(b[1][0], 2);
}

TEST(BisymmetricMatrix_Test, CopyAssignment) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);
  BisymmetricMatrix b;
  b = a;

  ASSERT_EQ(b.getSize(), test_size);
  ASSERT_EQ(b[0][0], 1);
  ASSERT_EQ(b[1][0], 2);
}

TEST(BisymmetricMatrix_Test, Plus) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);
  BisymmetricMatrix b;
  b = a + a;

  ASSERT_EQ(b.getSize(), test_size);
  ASSERT_EQ(b[0][0], 2);
  ASSERT_EQ(b[1][0], 4);
}

TEST(BisymmetricMatrix_Test, Minus) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);
  BisymmetricMatrix b;
  b = a - a;

  ASSERT_EQ(b.getSize(), test_size);
  ASSERT_EQ(b[0][0], 0);
  ASSERT_EQ(b[1][0], 0);
}

TEST(BisymmetricMatrix_Test, Multiply) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);
  BisymmetricMatrix b;
  b = a * a;

  ASSERT_EQ(b.getSize(), test_size);
  ASSERT_EQ(b[0][0], 5);
  ASSERT_EQ(b[1][0], 4);
}

TEST(BisymmetricMatrix_Test, Divide) {
  int test_size = 2;
  std::vector<std::vector<double>> test_matrix = {{1, 2}, {2, 1}};
  BisymmetricMatrix a(test_matrix);
  BisymmetricMatrix b;
  b = a / a;

  ASSERT_EQ(b.getSize(), test_size);
  ASSERT_EQ(b[0][0], 2);
  ASSERT_DOUBLE_EQ(b[1][0], 2.5);
}
