// Copyright 2022 Kuklin Andrey

#include "include/modified_stack.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <utility>

ModifiedStack::ModifiedStack(size_t _maxSize) : size(0), maxSize(_maxSize) {
  if (_maxSize <= 0) throw _maxSize;

  mas = new std::pair<int, int>[maxSize];
}

ModifiedStack::~ModifiedStack() { delete[] mas; }

ModifiedStack::ModifiedStack(const ModifiedStack& mstack)
    : size(mstack.size), maxSize(mstack.maxSize) {
  mas = new std::pair<int, int>[maxSize];

  for (size_t i = 0; i < size; ++i) mas[i] = mstack.mas[i];
}

bool ModifiedStack::Empty() const { return size == 0; }

bool ModifiedStack::Full() const { return size == maxSize; }

void ModifiedStack::Push(int elem) {
  if (Full()) Resize();

  size_t minelem = Empty() ? elem : std::min(elem, mas[size - 1].second);
  mas[size] = std::make_pair(elem, minelem);
  ++size;
}

int ModifiedStack::Top() const {
  if (Empty()) throw size;

  return mas[size - 1].first;
}

void ModifiedStack::Pop() {
  if (Empty()) throw size;

  --size;
}

size_t ModifiedStack::Size() const { return size; }

void ModifiedStack::Clear() { size = 0; }

int ModifiedStack::MinElem() const {
  if (Empty()) throw size;

  return mas[size - 1].second;
}

void ModifiedStack::Resize() {
  maxSize == 0 ? maxSize++ : maxSize *= 2;
  std::pair<int, int>* newMas = new std::pair<int, int>[maxSize];
  for (size_t i = 0; i < size; ++i) newMas[i] = mas[i];

  delete[] mas;
  mas = newMas;
}

ModifiedStack& ModifiedStack::operator=(const ModifiedStack& mstack) {
  if (this != &mstack) {
    if (maxSize != mstack.maxSize) {
      delete mas;
      maxSize = mstack.maxSize;
      mas = new std::pair<int, int>[maxSize];
    }

    size = mstack.size;
    for (size_t i = 0; i < size; ++i) mas[i] = mstack.mas[i];
  }
  return *this;
}

bool ModifiedStack::operator==(const ModifiedStack& mstack) const {
  if (this != &mstack) {
    if (size != mstack.size) return false;
    for (size_t i = 0; i < size; i++) {
      if (mas[i] != mstack.mas[i]) return false;
    }
  }
  return true;
}

bool ModifiedStack::operator!=(const ModifiedStack& mstack) const {
  return !(*this == mstack);
}
