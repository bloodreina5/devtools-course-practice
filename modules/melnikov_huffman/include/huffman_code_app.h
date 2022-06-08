// Copyright 2022 Bulicheva Darya
#ifndef MODULES_MELNIKOV_HUFFMAN_INCLUDE_HUFFMAN_CODE_APP_H_
#define MODULES_MELNIKOV_HUFFMAN_INCLUDE_HUFFMAN_CODE_APP_H_

#include <string>

class Application {
 public:
    std::string operator()(int argc, const char* argv[]);
 private:
    static inline std::string help(const char* appname);
};

#endif  // MODULES_MELNIKOV_HUFFMAN_INCLUDE_HUFFMAN_CODE_APP_H_
