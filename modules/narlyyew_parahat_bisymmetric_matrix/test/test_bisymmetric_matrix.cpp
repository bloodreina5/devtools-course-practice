// Copyright 2022 Narlyyew Parahat

#include <gtest/gtest.h>

#include "include/Matrix.h"

TEST(narlyyew_parahat_bisymmetric_matrix, can_create_fixed_size) {
    int size = 4;
    Matrix m(size);

    EXPECT_EQ(size, m.GetSize());
}

TEST(narlyyew_parahat_bisymmetric_matrix, test_copy_constructor) {
    int size = 4;
    Matrix m(size);
    m.Insert(1, 1, 3);
    Matrix n(m);

    EXPECT_EQ(n.GetSize(), m.GetSize());
}

TEST(narlyyew_parahat_bisymmetric_matrix, test_get_element) {
    int size = 4;
    int element = 3;
    int row = 1, col = 1;
    Matrix m(size);
    m.Insert(row, col, element);

    EXPECT_EQ(element, m.GetElem(row, col));
}

TEST(narlyyew_parahat_bisymmetric_matrix, test_operator_equal) {
    int size = 4;
    Matrix m(size);
    int element = 3;
    int row = 1, col = 1;
    m.Insert(row, col, element);
    Matrix n = m;

    EXPECT_EQ(n.GetSize(), m.GetSize());
    EXPECT_EQ(n.GetElem(row, col), m.GetElem(row, col));
}

TEST(narlyyew_parahat_bisymmetric_matrix, test_throws_size_error) {
    int size = 4;
    Matrix m(size);
    int element = 3;
    int row = 5, col = 1;

    EXPECT_ANY_THROW(m.Insert(row, col, element));
}
