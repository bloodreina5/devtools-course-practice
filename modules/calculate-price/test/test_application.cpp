// Copyright 2022 Krivosheev Miron

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/application.h"

using ::testing::internal::RE;

class CalculateBooksPriceAppTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("calculate-price");
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
  CalculateBooksPriceApp app_;
  std::string output_;
};

TEST_F(CalculateBooksPriceAppTest, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application to calculate Harry Potter books price.");
}

TEST_F(CalculateBooksPriceAppTest, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "1", "2", "3", "4" };

  Act(args);

  Assert("ERROR: Should be 5 arguments.");
}

TEST_F(CalculateBooksPriceAppTest, Basket_With_One_Type_Book) {
  std::vector<std::string> args = { "7", "0", "0", "0", "0" };

  Act(args);

  Assert("56.0");
}

TEST_F(CalculateBooksPriceAppTest, Basket_With_Two_Type_Books) {
  std::vector<std::string> args = { "7", "1", "0", "0", "0" };

  Act(args);

  Assert("63.2");
}

TEST_F(CalculateBooksPriceAppTest, Basket_With_Five_Type_Books) {
  std::vector<std::string> args = { "1", "1", "1", "1", "1" };

  Act(args);

  Assert("30.0");
}

TEST_F(CalculateBooksPriceAppTest,
  Basket_With_Five_Type_Books_Different_Counts) {
  std::vector<std::string> args = { "5", "4", "3", "2", "1" };

  Act(args);

  Assert("100.4");
}
