// Copyright 2022 Gudkov Andrey

#ifndef MODULES_KRUGLOV_ALEKSEI_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_APP_H_
#define MODULES_KRUGLOV_ALEKSEI_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_APP_H_

#include <vector>
#include <string>
#include "include/segment_tree.h"

class Application {
 private:
    std::string getHelp(const char* appname);
 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_KRUGLOV_ALEKSEI_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_APP_H_
