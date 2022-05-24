// Copyright 2022 Remizova Antonina

#include "include/remizova_a_matrix.h"

template <class T>
std::ostringstream& operator<<(std::ostringstream& os, TMatrix<T> m) {
  auto data = m.getData();
  for (int i = 0; i < m.getRows(); ++i) {
    for (int j = 0; j < m.getCols(); ++j) {
      os << std::round(data[i][j]) << " ";
    }
  }
  return os;
}
