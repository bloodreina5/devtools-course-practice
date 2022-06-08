// Copyright 2022 Likashuk Diana

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>
#include "include/application.h"

using ::testing::internal::RE;

class BitArrayAppTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("krivosheev_bit_array");
    for (std::size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  BitArrayApp app_;
  std::string output_;
};

TEST_F(BitArrayAppTest, Is_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application to get or set bits in bit array.");
}

TEST_F(BitArrayAppTest, Is_Print_Help_Wgong_Count_Of_Arguments) {
  std::vector<std::string> args = {"101"};

  Act(args);

  Assert("ERROR: Should be 4 or 5 arguments.");
}

TEST_F(BitArrayAppTest, Can_Array_Contains_Not_1_0) {
  std::vector<std::string> args = { "105", "set", "1", "1" };

  Act(args);

  Assert("Arr must constains just 1 and 0!");
}

TEST_F(BitArrayAppTest, GetBit) {
  std::vector<std::string> args = { "101", "get", "1" };

  Act(args);

  Assert("Your bit is 0");
}

TEST_F(BitArrayAppTest, SetBit) {
  std::vector<std::string> args = { "101", "set", "1", "1"};

  Act(args);

  Assert("Your array: 111");
}

