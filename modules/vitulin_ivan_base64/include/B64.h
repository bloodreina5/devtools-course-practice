// Copyright 2022 Vitulin Ivan

#ifndef MODULES_VITULIN_IVAN_BASE64_INCLUDE_B64_H_
#define MODULES_VITULIN_IVAN_BASE64_INCLUDE_B64_H_

#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned char> decode(const std::string& encoded_string);
std::string encode(char* data, int data_size);

#endif  // MODULES_VITULIN_IVAN_BASE64_INCLUDE_B64_H_
