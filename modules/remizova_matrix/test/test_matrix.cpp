// Copyright 2022 Remizova Antonina

#include <gtest/gtest.h>
#include <vector>
#include "include/remizova_a_matrix.h"

TEST(TMatrix, can_create_int_null_matrix_with_positive_size) {
    ASSERT_NO_THROW(TMatrix<int> m(3, 4));
}

TEST(TMatrix, cannot_create_null_matrix_with_negative_rows) {
    ASSERT_ANY_THROW(TMatrix<int> m(-4, 2));
}

TEST(TMatrix, cannot_create_null_matrix_with_negative_cols) {
    ASSERT_ANY_THROW(TMatrix<int> m(4, -2));
}

TEST(TMatrix, can_create_int_matrix_with_given_value) {
    ASSERT_NO_THROW(TMatrix<int> m(3, 3, 5));
}

TEST(TMatrix, cannot_create_given_matrix_with_negative_rows) {
    ASSERT_ANY_THROW(TMatrix<int> m(-4, 2, 1));
}

TEST(TMatrix, cannot_create_given_matrix_with_negative_cols) {
    ASSERT_ANY_THROW(TMatrix<int> m(4, -2, 1));
}

TEST(TMatrix, can_create_copied_int_matrix) {
    TMatrix<int> m1(5, 5, 2);

    ASSERT_NO_THROW(TMatrix<int> m2(m1));
}

TEST(TMatrix, can_set_and_get_matrix) {
    TMatrix<int> m(2, 2);
    std::vector<std::vector<int>> v{ {-2, 3}, {8, 0} };
    m.setMatrix(v);

    EXPECT_EQ(m.getMatrix(), v);;
}

TEST(TMatrix, cannot_set_matrix_with_different_vec_rows) {
    TMatrix<int> m(2, 2);
    std::vector<std::vector<int>> v{ {-2, 3}, {8, 0}, {-4, -1} };

    ASSERT_ANY_THROW(m.setMatrix(v));
}

TEST(TMatrix, cannot_set_matrix_with_different_vec_cols) {
    TMatrix<int> m(2, 2);
    std::vector<std::vector<int>> v{ {-2, 3, 8}, { 0, -4, -1 } };

    ASSERT_ANY_THROW(m.setMatrix(v));
}

TEST(TMatrix, can_compare_identical_matrices) {
    TMatrix<int> m1(2, 2);
    std::vector<std::vector<int>> v{ {-2, 3}, {8, 0} };
    m1.setMatrix(v);
    TMatrix<int> m2(m1);

    EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, can_compare_matrices_with_same_elem_dif_row) {
    TMatrix<int> m1(2, 2, 4);
    TMatrix<int> m2(3, 2, 4);

    EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix, can_compare_matrices_with_same_elem_dif_cols) {
    TMatrix<int> m1(2, 2, 4);
    TMatrix<int> m2(2, 3, 4);

    EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix, can_compare_matrices_with_same_size_dif_elem) {
    TMatrix<int> m1(2, 2, 4);
    TMatrix<int> m2(2, 2, 5);

    EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix, can_non_compare_identical_matrices) {
    TMatrix<int> m1(2, 2);
    std::vector<std::vector<int>> v1{ {-2, 3}, {8, 0} };
    m1.setMatrix(v1);
    TMatrix<int> m2(m1);

    EXPECT_EQ(false, m1 != m2);
}

TEST(TMatrix, can_non_compare_matrices_with_same_elem_dif_rows) {
    TMatrix<int> m1(2, 2, 4);
    TMatrix<int> m2(3, 2, 4);

    EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, can_non_compare_matrices_with_same_elem_dif_cols) {
    TMatrix<int> m1(2, 2, 4);
    TMatrix<int> m2(2, 3, 4);

    EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, can_non_compare_matrices_with_same_size_dif_elem) {
    TMatrix<int> m1(2, 2, 4);
    TMatrix<int> m2(2, 2, 5);

    EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, can_assign_matrix_with_same_size) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(2, 2, 3);

    ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, can_assign_equal_matrix) {
    TMatrix<int> m1(2, 2, 5);

    ASSERT_NO_THROW(m1 = m1);
}

TEST(TMatrix, can_assign_matrix_with_different_rows) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(3, 2, 3);

    ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, can_assign_matrix_with_different_cols) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(2, 3, 3);

    ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, can_compare_matrix_with_same_size) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(2, 2, 3);

    ASSERT_NO_THROW(m1 + m2);
}

TEST(TMatrix, cannot_compare_matrix_with_different_rows) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(4, 2, 3);

    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, cannot_compare_matrix_with_different_cols) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(2, 4, 3);

    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_substract_matrix_with_same_size) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(2, 2, 3);

    ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cannot_substract_matrix_with_different_rows) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(4, 2, 3);

    ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, cannot_substract_matrix_with_different_cols) {
    TMatrix<int> m1(2, 2, 5);
    TMatrix<int> m2(2, 4, 3);

    ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, can_multiply_matrix_with_cols1_equal_rows2) {
    TMatrix<int> m1(4, 2, 5);
    TMatrix<int> m2(2, 3, 3);

    ASSERT_NO_THROW(m1 * m2);
}

TEST(TMatrix, cannot_multiply_matrix_with_different_cols1_rows2) {
    TMatrix<int> m1(4, 2);
    TMatrix<int> m2(3, 3);

    ASSERT_ANY_THROW(m1 * m2);
}

TEST(TMatrix, can_delete_row_and_col) {
    TMatrix<int> m1(3, 3);
    std::vector<std::vector<int>> v1{ {-2, 3, 4}, {5, 1, -7}, {8, 0, 9} };
    m1.setMatrix(v1);
    TMatrix<int> m2(2, 2);
    std::vector<std::vector<int>> v2{ {1, -7}, {0, 9} };
    m2.setMatrix(v2);

    int i = 0, j = 0;

    EXPECT_EQ(m2, m1.matrixWithoutRowAndCol(i, j));
}

TEST(TMatrix, can_find_determinant_square_matrix_1x1) {
    TMatrix<int> m(1, 1, 17);

    int det = 17;

    EXPECT_EQ(det, m.determinant(m));
}

TEST(TMatrix, can_find_determinant_square_matrix_2x2) {
    TMatrix<int> m(2, 2);
    std::vector<std::vector<int>> v{ {3, -7}, {4, 2} };
    m.setMatrix(v);

    int det = 34;

    EXPECT_EQ(det, m.determinant(m));
}

TEST(TMatrix, can_find_determinant_square_matrix_3x3) {
    TMatrix<int> m(3, 3);
    std::vector<std::vector<int>> v{ {-2, 3, 4}, {5, 1, -7}, {8, 0, 9} };
    m.setMatrix(v);

    int det = -353;

    EXPECT_EQ(det, m.determinant(m));
}

TEST(TMatrix, cannot_find_determinant_not_square_matrix) {
    TMatrix<int> m(3, 4);

    ASSERT_ANY_THROW(m.determinant(m));
}

TEST(TMatrix, can_transpose_matrix) {
    TMatrix<int> m1(2, 3);
    std::vector<std::vector<int>> v1{ {1, 2, 3}, {4, 5, 6} };
    m1.setMatrix(v1);
    TMatrix<int> m2(3, 2);
    std::vector<std::vector<int>> v2{ {1, 4}, {2, 5}, {3, 6} };
    m2.setMatrix(v2);

    EXPECT_EQ(m1.transposition(), m2);
}

TEST(TMatrix, can_convert_matrix_to_alliance) {
    TMatrix<int> m1(3, 3);
    std::vector<std::vector<int>> v1{ {2, 6, 5}, {-1, 9, 8}, {8, 0, 2} };
    m1.setMatrix(v1);
    TMatrix<int> m2(3, 3);
    std::vector<std::vector<int>> v2{ {18, -12, 3},
        {66, -36, -21}, {-72, 48, 24} };
    m2.setMatrix(v2);

    EXPECT_EQ(m1.alliance(), m2);
}


TEST(TMatrix, can_find_reverse_matrix) {
    TMatrix<int> m1(3, 3);
    std::vector<std::vector<int>> v1{ {2, 6, 5}, {-1, 9, 8}, {8, 0, 2} };
    m1.setMatrix(v1);
    TMatrix<int> m2(3, 3);
    std::vector<std::vector<int>> v2{ {18 / 72, -12 / 72, 3 / 72},
        {66 / 72, -36 / 72, -21 / 72}, {-72 / 72, 48 / 72, 24 / 72} };
    m2.setMatrix(v2);

    EXPECT_EQ(m1.reverse(), m2);
}

TEST(TMatrix, cannot_find_reverse_not_square_matrix) {
    TMatrix<double> m(3, 4);

    ASSERT_ANY_THROW(m.reverse());
}

TEST(TMatrix, cannot_find_reverse_matrix_with_null_determinant) {
    TMatrix<int> m(3, 3);
    std::vector<std::vector<int>> v{ {-2, 7, -3},
        {4, -14, 6}, {-3, 7, 13} };  // det = 0
    m.setMatrix(v);

    ASSERT_ANY_THROW(m.reverse());
}
