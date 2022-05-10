// Copyright 2022 Kamenev Ilya

#ifndef MODULES_KAMENEV_HANOI_TOWER_INCLUDE_HANOI_TOWER_H_
#define MODULES_KAMENEV_HANOI_TOWER_INCLUDE_HANOI_TOWER_H_

#include <stack>
#include <vector>
#include <string>
#pragma once

class HanoiTower {
 private:
  int _fromNum = 1, _toNum = 2, _bufNum = 3;
  int _ringCount;
  bool _isInstructionPrinted = false;
  std::vector<std::string> _instructions;
  std::stack<int> _fromCol;
  std::stack<int> _toCol;
  std::stack<int> _bufCol;

  void SolveHanoiRecursive(int ringCount, int from, int to);
  void MakeStep(int from, int to);
  void PrintLastInstruction();
  void AddInstruction(int from, int to);
 public:
  HanoiTower();
  explicit HanoiTower(int ringCount);
  HanoiTower(int ringCount, bool isInstructionPrinted);
  int GetColSize(int colNum);
  void SolveHanoi();
  void SolveHanoi(int ringCount);
  void PrintAllInstructions();
};

#endif  // MODULES_KAMENEV_HANOI_TOWER_INCLUDE_HANOI_TOWER_H_
