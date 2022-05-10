// Copyright 2022 Belyaev Ilya

#include <gtest/gtest.h>
#include "include/Vfig.h"




TEST(belyaev_volume, v1) {
  ASSERT_NO_THROW(Body_Volume());
}
TEST(belyaev_volume, v2) {
  ASSERT_NO_THROW(Body_Volume(1, 2));
}
TEST(belyaev_volume, v3) {
  ASSERT_NO_THROW(Body_Volume(-1, 20));
}
TEST(belyaev_volume, v4) {
  ASSERT_NO_THROW(Body_Volume(0, 0));
}
TEST(belyaev_volume, v5) {
  Body_Volume v;
  double x = 5;
  double S =  v.section_function_Ball(x);
  ASSERT_EQ(S, PI * x * x);
}
TEST(belyaev_volume, v6) {
  Body_Volume v;
  double x = -4;
  double S = v.section_function_Ball(x);
  ASSERT_EQ(S, PI * x * x);
}
TEST(belyaev_volume, v7) {
  Body_Volume v;
  double a = 0;
  double b = 0;
  double V = v.calculation_volume_Ball(a, b, 1000);
  ASSERT_EQ(V, 0);
}
TEST(belyaev_volume, v8) {
  Body_Volume v;
  double a = 0;
  double b = 1;
  double V = v.calculation_volume_Ball(a, b, 1000);
  ASSERT_NEAR(V, 1.045, 0.005);
}
TEST(belyaev_volume, v11) {
  Body_Volume v;
  double a = -1;
  double b = 5;
  double V = v.calculation_volume_Ball(a, b, 1000);
  ASSERT_NEAR(V, 131.65, 0.005);
}
TEST(belyaev_volume, v9) {
  Body_Volume v;
  double a = 0;
  double b = 1;
  double V = v.calculation_volume_cube(a, b);
  ASSERT_NEAR(V, 1, 0.00005);
}
TEST(belyaev_volume, v10) {
  Body_Volume v;
  double a = -5;
  double b = 10;
  double V = v.calculation_volume_cube(a, b);
  ASSERT_NEAR(V, 3375, 0.00005);
}
