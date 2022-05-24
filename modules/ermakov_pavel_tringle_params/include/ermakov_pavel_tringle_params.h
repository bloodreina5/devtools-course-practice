// Copyright 2022 Ermakov Pavel

#ifndef MODULES_ERMAKOV_PAVEL_TRINGLE_PARAMS_INCLUDE_ERMAKOV_PAVEL_TRINGLE_PARAMS_H_
#define MODULES_ERMAKOV_PAVEL_TRINGLE_PARAMS_INCLUDE_ERMAKOV_PAVEL_TRINGLE_PARAMS_H_

#include <utility>
#include <vector>

class _Triangle {
  std::pair<float, float> a;
  std::pair<float, float> b;
  std::pair<float, float> c;

 public:
  _Triangle();
  _Triangle(std::pair<float, float> _a, std::pair<float, float> _b,
            std::pair<float, float> _c);
  std::pair<float, float> get_a_poin();
  std::pair<float, float> get_b_poin();
  std::pair<float, float> get_c_poin();
  void set_a_poin(std::pair<float, float> _p);
  void set_b_poin(std::pair<float, float> _p);
  void set_c_poin(std::pair<float, float> _p);
  float get_perimetr();
  float get_square();
  float get_height(float _side);
  float get_side_lenght(std::pair<float, float> _a, std::pair<float, float> _b);
  ~_Triangle();
};
#endif  // MODULES_ERMAKOV_PAVEL_TRINGLE_PARAMS_INCLUDE_ERMAKOV_PAVEL_TRINGLE_PARAMS_H_
