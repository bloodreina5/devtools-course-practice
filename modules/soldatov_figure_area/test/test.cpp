// Copyright 2022 Soldatov Gleb

#include <gtest/gtest.h>
#include "include/soldatov_figure_area.h"


TEST(soldatov_area, can_create_default) {
    ASSERT_NO_THROW(figureArea());
}
TEST(soldatov_area, can_create_init) {
    ASSERT_NO_THROW(figureArea(7));
}
TEST(soldatov_area, can_create_init2) {
    ASSERT_NO_THROW(figureArea(7, 9, 12));
}
TEST(soldatov_area, can_create_negative) {
    ASSERT_NO_THROW(figureArea(-7));
}
TEST(soldatov_area, can_create_negative2) {
    ASSERT_NO_THROW(figureArea(-7, 9, 12));
}
TEST(soldatov_area, can_create_zeroes) {
    ASSERT_NO_THROW(figureArea(0));
}
TEST(soldatov_area, can_create_zeroes2) {
    ASSERT_NO_THROW(figureArea(0, 0, 0));
}
TEST(soldatov_area, area_ball) {
    double x = 5.0;
    figureArea ball(x);
    double areaBall = ball.ballArea();
    ASSERT_DOUBLE_EQ(areaBall, 4 * PI * x * x);
}
TEST(soldatov_area, neg_area_ball) {
    double x = -4;
    figureArea ball(x);
    ASSERT_ANY_THROW(ball.ballArea());
}
TEST(soldatov_area, zeroes_area_ball) {
    double x = 0;
    figureArea ball(x);
    ASSERT_ANY_THROW(ball.ballArea());
}
TEST(soldatov_area, area_rectangle) {
    double x, y, z;
    x = y = z = 7.0;
    figureArea rectangle(x, y, z);
    double areaRec = rectangle.rectangleArea();
    ASSERT_DOUBLE_EQ(areaRec, (2.0 * x * y) + (2.0 * x * z) + (2.0 * y * z));
}
TEST(soldatov_area, neg_area_rectangle) {
    double x, y, z;
    x = y = z = -7;
    figureArea rectangle(x, y, z);
    ASSERT_ANY_THROW(rectangle.rectangleArea());
}
TEST(soldatov_area, zeroes_area_rectangle) {
    double x, y, z;
    x = y = z = 0;
    figureArea rectangle(x, y, z);
    ASSERT_ANY_THROW(rectangle.rectangleArea());
}
