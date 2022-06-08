// Copyright 2022 Zaitsev Alexander

#ifndef MODULES_KUKLIN_ANDREY_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_APPLICATION_H_
#define MODULES_KUKLIN_ANDREY_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_APPLICATION_H_

#include <sstream>
#include <string>

#include "include/modified_stack.h"

class ModifiedStackApp {
 public:
  ModifiedStackApp() = default;
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  // MODULES_KUKLIN_ANDREY_MODIFIED_STACK_INCLUDE_MODIFIED_STACK_APPLICATION_H_
