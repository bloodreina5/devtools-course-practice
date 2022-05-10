// Copyright 2022 Kamenev Ilya

#include "include/hanoi_tower.h"
#include <string>
#include <iostream>

HanoiTower::HanoiTower() {}

HanoiTower::HanoiTower(int ringCount) {
  _ringCount = ringCount;
  for (int i = 1; i <= _ringCount; i++) {
    _fromCol.push(i);
  }
}

HanoiTower::HanoiTower(int ringCount, bool isInstructionPrinted)
  : HanoiTower(ringCount) {
  _isInstructionPrinted = isInstructionPrinted;
}

void HanoiTower::PrintLastInstruction() {
  if (!_instructions.empty()) {
    std::cout << _instructions.back();
  }
}

void HanoiTower::MakeStep(int from, int to) {
  int tmp;

  switch (from) {
    case 1:
      tmp = _fromCol.top();
      _fromCol.pop();
      break;
    case 2:
      tmp = _toCol.top();
      _toCol.pop();
      break;
    case 3:
      tmp = _bufCol.top();
      _bufCol.pop();
      break;
  }

  switch (to) {
    case 1:
      _fromCol.push(tmp);
      break;
    case 2:
      _toCol.push(tmp);
      break;
    case 3:
      _bufCol.push(tmp);
      break;
  }

  AddInstruction(from, to);
  if (_isInstructionPrinted) {
    PrintLastInstruction();
  }
}

void HanoiTower::AddInstruction(int from, int to) {
  std::string instruction = "Move from " + std::to_string(from) +
      " to " + std::to_string(to) + "\n";
  _instructions.push_back(instruction);
}

void HanoiTower::SolveHanoiRecursive(int ringCount, int from, int to) {
  if (ringCount < 1) {
    return;
  }
  if (ringCount == 1) {
    MakeStep(from, to);
  } else {
    int tmp = 6 - from - to;
    SolveHanoiRecursive(ringCount - 1, from, tmp);
    MakeStep(from, to);
    SolveHanoiRecursive(ringCount - 1, tmp, to);
  }
}

void HanoiTower::SolveHanoi() {
  SolveHanoiRecursive(_ringCount, _fromNum, _toNum);
}

void HanoiTower::SolveHanoi(int ringCount) {
  _ringCount = ringCount;
  while (!_fromCol.empty()) {
    _fromCol.pop();
  }
  while (!_toCol.empty()) {
    _toCol.pop();
  }
  for (int i = 1; i <= _ringCount; i++) {
    _fromCol.push(i);
  }
  SolveHanoiRecursive(ringCount, _fromNum, _toNum);
}

int HanoiTower::GetColSize(int colNum) {
  switch (colNum) {
    case 1:
      return _fromCol.size();
    case 2:
      return _toCol.size();
    case 3:
      return _bufCol.size();
  }
  return 0;
}

void HanoiTower::PrintAllInstructions() {
  for (auto &el : _instructions) {
    std::cout << el;
  }
}
