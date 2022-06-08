// Copyright 2022 Bulicheva Darya

#include <vector>

#include "include/bil_interpol.h"

bilen_interpol::bilen_interpol() {
    std::vector<double> vect(4, 10);
    arr = vect;
}

bilen_interpol::bilen_interpol(std::vector<double> _arr) {
    arr = _arr;
}

double bilen_interpol::interpolate() {
    double res;
    double r1;
    double r2;
    double x0 = 10;
    double x1 = 20;
    double x2 = 30;
    double y2 = 30;
    double y1 = 20;
    double y0 = 10;
    r1 = arr[0] + (x1 - x0) * ((arr[1] - arr[0]) / (x2 - x0));
    r2 = arr[2] + (x1 - x0) * ((arr[3] - arr[2]) / (x2 - x0));
    res = r1 + (y1 - y2) * ((r2 - r1) / (y0 - y2));
    return res;
}

bilen_interpol::~bilen_interpol() {
    arr.clear();
}
