// Copyright 2022 Kuklin Andrey

#ifndef MODULES_KUKLIN_ANDREY_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_H_
#define MODULES_KUKLIN_ANDREY_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_H_

#include <iostream>
#include <utility>
using std::size_t;

class ModifiedStack {
  size_t size, maxSize;
  std::pair<int, int>* mas;

  void Resize();

 public:
  explicit ModifiedStack(size_t _maxSize = 10);
  explicit ModifiedStack(const ModifiedStack& mstack);
  ~ModifiedStack();

  bool Empty() const;
  bool Full() const;
  void Push(int elem);
  int Top() const;
  void Pop();
  size_t Size() const;
  void Clear();
  int MinElem() const;

  ModifiedStack& operator=(const ModifiedStack& mstack);
  bool operator==(const ModifiedStack& mstack) const;
  bool operator!=(const ModifiedStack& mstack) const;
};

#endif  // MODULES_KUKLIN_ANDREY_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_H_
