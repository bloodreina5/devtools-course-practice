// Copyright 2022 Javier Galindo

#ifndef MODULES_PYATCKIN_NIKOLAY_RB_TREE_INCLUDE_RB_TREE_APP_H_
#define MODULES_PYATCKIN_NIKOLAY_RB_TREE_INCLUDE_RB_TREE_APP_H_
#include <string>
#include <sstream>
#include <vector>
#include "include/rb_tree.h"
#include "include/rb_operation.h"

class RBTreeApp {
 public:
       RBTreeApp() = default;
       std::string operator()(int argc, const char** argv);
 private:
       std::string Help(const char* appname);
       int ParseOperation(const char** argv);
       int ParseNumber(const char* s);
       RBTree t_;
       std::stringstream out_;
};

#endif  // MODULES_PYATCKIN_NIKOLAY_RB_TREE_INCLUDE_RB_TREE_APP_H_
