// Copyright 2022 Javier Galindo

#ifndef MODULES_GALINDO_30_RULE_INCLUDE_GALINDO_30_RULE_H_
#define MODULES_GALINDO_30_RULE_INCLUDE_GALINDO_30_RULE_H_

#include <vector>

enum class CellState {
    DEAD,
    ALIVE
};

class CellularAutomaton {
 public:
     CellularAutomaton(const unsigned int rows, const unsigned int cols);
     CellularAutomaton(const unsigned int rows, const unsigned int cols,
         const std::vector<CellState>& states);
     ~CellularAutomaton() = default;

     const std::vector <std::vector<CellState>>& get_state() const;

     void iterate(const unsigned int iterations);

 private:
     std::vector<std::vector<CellState>> state;
     unsigned int cols = 0;
     unsigned int rows = 0;

     CellState rules(const int row, const int col) const;
};


#endif  // MODULES_GALINDO_30_RULE_INCLUDE_GALINDO_30_RULE_H_
