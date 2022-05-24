// Copyright 2022 Frolov Gleb

#include <string>

#ifndef MODULES_FROLOV_REGULAR_EXPRESSIONS_INCLUDE_REGULAR_EXPRESSIONS_H_
#define MODULES_FROLOV_REGULAR_EXPRESSIONS_INCLUDE_REGULAR_EXPRESSIONS_H_

class Text_for_regexp {
 private:
  std::string text;
 public:
  Text_for_regexp();
  explicit Text_for_regexp(std::string _text);
  std::string Get_text();
  std::string Search_for_regexp(std::string regexp);
};

#endif  // MODULES_FROLOV_REGULAR_EXPRESSIONS_INCLUDE_REGULAR_EXPRESSIONS_H_
