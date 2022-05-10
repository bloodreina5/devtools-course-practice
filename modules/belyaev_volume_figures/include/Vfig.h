// Copyright 2022 Belyaev Ilya
#ifndef MODULES_BELYAEV_VOLUME_FIGURES_INCLUDE_VFIG_H_
#define MODULES_BELYAEV_VOLUME_FIGURES_INCLUDE_VFIG_H_
#include <stdlib.h>
#include <math.h>
const double PI = 3.14;


class Body_Volume {
 private:
  double a;  // first x-axis coordinate
  double b;  // second x-axis coordinate
 public:
     int n = 100;
     Body_Volume();  // default constructor
     Body_Volume(double _a, double _b);  // constructor
     double section_function_Ball(double x);  // section function
     double calculation_volume_Ball(double a, double b, int n);  // ball volume
     double calculation_volume_cube(double a, double b);  // cube volume
};
#endif  // MODULES_BELYAEV_VOLUME_FIGURES_INCLUDE_VFIG_H_
