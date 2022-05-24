// Copyright 2022 Remizova Antonina & Grohev Nikolay
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/matrix_app.h"

using ::testing::internal::RE;

class MatrixCalculatorTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("MatrixCalculator");
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
  MatrixCalculator app_;
  std::string output_;
};

TEST_F(MatrixCalculatorTest, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application which allows you.");
}

TEST_F(MatrixCalculatorTest, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = {"1", "2", "3", "*"};

  Act(args);

  Assert("Should be 7 arguments!");
}

TEST_F(MatrixCalculatorTest, Can_Compare_For_Equality) {
  std::vector<std::string> args = {"2", "2", "3", "2", "2",
                                   "3", "=="};

  Act(args);

  Assert("res = 1");
}


TEST_F(MatrixCalculatorTest, Can_Compare_For_Inequality) {
  std::vector<std::string> args = {"2", "2", "3", "2", "2", "3", "!="};

  Act(args);

  Assert("res = 0");
}

TEST_F(MatrixCalculatorTest, Can_Determinant) {
  std::vector<std::string> args = {"2", "2", "3", "2", "2", "3", "det"};

  Act(args);

  Assert("res = 0");
}
