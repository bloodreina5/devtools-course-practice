// Copyright 2022 Melnikov Aleksei

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/application.h"

using ::testing::internal::RE;


class HorseMinRangeAppTest : public ::testing::Test {
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
  HorseMinRangeApp app_;
  std::string output_;
};



TEST_F(HorseMinRangeAppTest, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application to count steps by chess horse");
}

TEST_F(HorseMinRangeAppTest, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "a2" };

  Act(args);

  Assert("ERROR: Unvaleble count of parameters.");
}

TEST_F(HorseMinRangeAppTest, Is_Checking_Correct_Of_Values_Wrong_Num) {
  std::vector<std::string> args = { "a9", "b2", };

  Act(args);

  Assert("Points are not valid!");
}

TEST_F(HorseMinRangeAppTest, Is_Checking_Correct_Of_Values_Wrong_Letter) {
  std::vector<std::string> args = { "a4", "i2", };

  Act(args);

  Assert("Points are not valid!");
}

TEST_F(HorseMinRangeAppTest, Is_Checking_Correct_Of_Values_Wrong_Barrier) {
  std::vector<std::string> args = { "a4", "b2", "k4"};

  Act(args);

  Assert("Barriers are not valid!");
}

TEST_F(HorseMinRangeAppTest, AppWorkCorrct) {
  std::vector<std::string> args = { "a1", "g8" };

  Act(args);

  Assert("The number of steps: 5");
}

TEST_F(HorseMinRangeAppTest, AppWorkCorrct_With_Barrier) {
  std::vector<std::string> args = { "a1", "b7", "g8" };

  Act(args);

  Assert("The number of steps: 3");
}
