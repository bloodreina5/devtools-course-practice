// Copyright 2022 Belyaev Ilya

#include "include/Vfig.h"
#include <math.h>
#include <cmath>
#include <iostream>


Body_Volume::Body_Volume() {
  this->a = {5};
  this->b = {10};
  if (b < a) throw "cannot";
}
Body_Volume::Body_Volume(double _a, double _b) {
    this->a = _a;
    this->b = _b;
}

double Body_Volume::section_function_Ball(double x) {
    return (PI * x*x);
}

double Body_Volume::calculation_volume_Ball(double a, double b, int n) {
  double h;
  double sum = 0.0;
  h = (b - a) / n;

  for (int i = 0; i < n; i++) {
    sum += section_function_Ball(a + i * h);
  }
  return (sum * h);
}

double Body_Volume::calculation_volume_cube(double a, double b) {
    return pow((b-a), 3);
}
