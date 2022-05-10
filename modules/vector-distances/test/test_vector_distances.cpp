// Copyright 2022 Maksim Orlov

#include <gtest/gtest.h>
#include <vector>
#include "../include/vector-distances.h"

TEST(Orlov_Maksim_VectorDistanceTest, can_create_vector) {
    // Arrange
    std::vector<float> _v = { 1.0, 2.0, 3.0 };

    // Act
    Vector v(_v);
    std::vector<float> data;
    v.getData(&data);

    // Assert
    ASSERT_EQ(data.size(), _v.size());
    for (unsigned int i = 0; i < data.size(); ++i) {
        EXPECT_EQ(data[i], _v[i]);
    }
}

TEST(Orlov_Maksim_VectorDistanceTest, can_copy_vector) {
    // Arrange
    std::vector<float> _v = { 1.0, 2.0, 3.0 };

    // Act
    Vector v1(_v);
    Vector v2(v1);
    std::vector<float> data1, data2;
    v1.getData(&data1);
    v2.getData(&data2);

    // Assert
    ASSERT_EQ(data2.size(), data1.size());
    for (unsigned int i = 0; i < data2.size(); ++i) {
        EXPECT_EQ(data2[i], data1[i]);
    }
}

TEST(Orlov_Maksim_VectorDistanceTest, can_set_data) {
    // Arrange
    std::vector<float> _v = { 1.0, 2.0, 3.0 };

    // Act
    Vector v1({ 0, 0, 0 });
    v1.setData(_v);
    std::vector<float> data;
    v1.getData(&data);

    // Assert
    ASSERT_EQ(data.size(), _v.size());
    for (unsigned int i = 0; i < data.size(); ++i) {
        EXPECT_EQ(data[i], _v[i]);
    }
}

TEST(Orlov_Maksim_VectorDistanceTest, can_assign_vector) {
    // Arrange
    std::vector<float> _v = { 1.0, 2.0, 3.0 };

    // Act
    Vector v1(_v);
    Vector v2({ 0, 0, 0 });
    v2 = v1;
    std::vector<float> data1, data2;
    v1.getData(&data1);
    v2.getData(&data2);

    // Assert
    ASSERT_EQ(data2.size(), data1.size());
    for (unsigned int i = 0; i < data2.size(); ++i) {
        EXPECT_EQ(data2[i], data1[i]);
    }
}

TEST(Orlov_Maksim_VectorDistanceTest,
    cant_calculate_Linf_distance_between_vectors_of_different_sizes) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0, 4.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Assert
    ASSERT_ANY_THROW(v1.Linf(v2));
}

TEST(Orlov_Maksim_VectorDistanceTest, Linf_empty_vectors_throw) {
    // Arrange
    std::vector<float> _v1 = { };
    std::vector<float> _v2 = { };
    Vector v1(_v1);
    Vector v2(_v2);

    // Assert
    ASSERT_ANY_THROW(v1.Linf(v2));
}

TEST(Orlov_Maksim_VectorDistanceTest, Linf_equal) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res;
    res = v1.Linf(v2);

    // Assert
    EXPECT_NEAR(0.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, Linf) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 0.0, 4.0, 6.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.Linf(v2);

    // Assert
    EXPECT_NEAR(3.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest,
    cant_calculate_Lp_distance_between_vectors_of_different_sizes) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0, 4.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Assert
    ASSERT_ANY_THROW(v1.L(1, v2));
}

TEST(Orlov_Maksim_VectorDistanceTest, Lp_empty_vectors_throw) {
    // Arrange
    std::vector<float> _v1 = { };
    std::vector<float> _v2 = { };
    Vector v1(_v1);
    Vector v2(_v2);

    // Assert
    ASSERT_ANY_THROW(v1.L(1, v2));
}

TEST(Orlov_Maksim_VectorDistanceTest, L1_equal) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(1, v2);

    // Assert
    EXPECT_NEAR(0.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L1) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 0.0, 4.0, 6.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(1, v2);

    // Assert
    EXPECT_NEAR(6.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L2_equal) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(2, v2);

    // Assert
    EXPECT_NEAR(0.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L2) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 0.0, 4.0, 6.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(2, v2);

    // Assert
    EXPECT_NEAR(3.742, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L3_equal) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(3, v2);

    // Assert
    EXPECT_NEAR(0.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L3) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 0.0, 4.0, 6.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(3, v2);

    // Assert
    EXPECT_NEAR(3.302, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L4_equal) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 1.0, 2.0, 3.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(4, v2);

    // Assert
    EXPECT_NEAR(0.0, res, 0.01);
}

TEST(Orlov_Maksim_VectorDistanceTest, L4) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 0.0, 4.0, 6.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Act
    float res = v1.L(4, v2);

    // Assert
    EXPECT_NEAR(3.146, res, 0.01);
}

TEST(Pinezhanin_Evgeny_VectorDistanceTest,
    cant_calculate_Lp_distance_between_vectors_if_p_less_one) {
    // Arrange
    std::vector<float> _v1 = { 1.0, 2.0, 3.0 };
    std::vector<float> _v2 = { 0.0, 4.0, 6.0 };
    Vector v1(_v1);
    Vector v2(_v2);

    // Assert
    ASSERT_ANY_THROW(v1.L(0, v2));
}
