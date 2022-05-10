// Copyright 2022 Javier Galindo

#include <vector>
#include "include/galindo_30_rule.h"

CellularAutomaton::CellularAutomaton(const unsigned int rows,
    const unsigned int cols) {
    if (rows == 0 || cols == 0) {
          throw "The size of the columns and rows must be 0";
    }
    this->rows = rows;
    this->cols = cols;

    state.resize(rows);
    for (unsigned int r = 0; r < rows; r++) {
           state[r].resize(cols, CellState::DEAD);
    }
}
CellularAutomaton::CellularAutomaton(const unsigned int rows,
    const unsigned int cols, const std::vector<CellState>& states) {
    if (rows == 0 || cols == 0) {
          throw "The size of the columns and rows must be 0";
    }
    this->rows = rows;
    this->cols = cols;

    state.resize(rows);
    state[0] = states;
    for (unsigned int r = 1; r < rows; r++) {
          state[r].resize(cols, CellState::DEAD);
    }
}
template<class T>
void resize(std::vector<std::vector<T>>* target,
    const unsigned int dx, const unsigned int dy) {
    target->resize(dx);
    for (unsigned int i = 0; i < dx; i++) {
         target[i]->resize(dy);
    }
}

const std::vector<std::vector<CellState>>&
CellularAutomaton::get_state() const {
     return state;
}

void CellularAutomaton::iterate(const unsigned int iterations) {
    unsigned int rows = static_cast<unsigned int>(state.size());
    unsigned int cells = 0;
    if (rows != 0) {
          cells = static_cast<unsigned int>(state[0].size());
    }

    std::vector<CellState> new_state(cols);

    for (unsigned int iteration = 0; iteration < iterations; iteration++) {
        for (unsigned int r = 0; r < rows - 1; r++) {
            for (unsigned int c = 1; c < cells - 1; c++) {
                     new_state[c] = rules(r, c);
            }
              state[r + 1] = new_state;
        }
    }
}

CellState CellularAutomaton::rules(const int row, const int col) const {
    if (state[row][col - 1] == CellState::DEAD &&
        state[row][col] == CellState::DEAD &&
        state[row][col + 1] == CellState::ALIVE) {
        return CellState::ALIVE;
    }
    if (state[row][col - 1] == CellState::DEAD &&
        state[row][col] == CellState::ALIVE &&
        state[row][col + 1] == CellState::DEAD) {
        return CellState::ALIVE;
    }
    if (state[row][col - 1] == CellState::DEAD &&
        state[row][col] == CellState::ALIVE &&
        state[row][col + 1] == CellState::ALIVE) {
        return CellState::ALIVE;
    }
    if (state[row][col - 1] == CellState::ALIVE &&
        state[row][col] == CellState::DEAD &&
        state[row][col + 1] == CellState::DEAD) {
        return CellState::ALIVE;
    }
    return CellState::DEAD;
}

