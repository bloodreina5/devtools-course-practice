// Copyright 2022 Bulicheva Darya

#ifndef MODULES_BULICHEVA_DARYA_BIL_INTERPOL_INCLUDE_BIL_INTERPOL_H_
#define MODULES_BULICHEVA_DARYA_BIL_INTERPOL_INCLUDE_BIL_INTERPOL_H_

#include <vector>

class bilen_interpol {
    std::vector<double> arr;
 public:
    bilen_interpol();
    explicit bilen_interpol(std::vector<double> _arr);
    double interpolate();
    ~bilen_interpol();
};

#endif  // MODULES_BULICHEVA_DARYA_BIL_INTERPOL_INCLUDE_BIL_INTERPOL_H_
