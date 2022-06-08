// Copyright 2022 Melnikov Aleksei

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/application.h"

using ::testing::internal::RE;

class NumCompAppTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("graph-num-comp");
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
  NumCompApp app_;
  std::string output_;
};

TEST_F(NumCompAppTest, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application to count the number of " \
    "connectivity components in graph.");
}

TEST_F(NumCompAppTest, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "1", "2", "3", "4" };

  Act(args);

  Assert("ERROR: Unvaleble count of parameters.");
}

TEST_F(NumCompAppTest, Is_Checking_Correct_Of_Values) {
  std::vector<std::string> args = { "2", "20", "01" };

  Act(args);

  Assert("Values can be 1 or 0 only!.");
}

TEST_F(NumCompAppTest, AppWorkCorrct_1) {
  std::vector<std::string> args = { "3", "011", "101", "110" };

  Act(args);

  Assert("The number of connectivity components is 1");
}

TEST_F(NumCompAppTest, AppWorkCorrct_2) {
  std::vector<std::string> args = { "4", "0100",
    "1000", "0001", "0010" };

  Act(args);

  Assert("The number of connectivity components is 2");
}
