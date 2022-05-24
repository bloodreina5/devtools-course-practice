// Copyright 2022 Pyatckin Nikolay

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/template_heap_app.h"

using ::testing::internal::RE;

class HeapAppTest : public ::testing::Test {
 protected:
     // virtual void SetUp() {}

     void Act(std::vector<std::string> args_) {
         std::vector<const char*> options;

         options.push_back("appname");
         for (size_t i = 0; i < args_.size(); ++i) {
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
    Heap_App app_;
    std::string output_;
};

TEST_F(HeapAppTest, Test_Return_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("");
}

TEST_F(HeapAppTest, Test_Return_Help_With_Flag) {
    // Arrange
    std::vector<std::string> args = {"help"};

    // Act
    Act(args);

    // Assert
    Assert("");
}

TEST_F(HeapAppTest, Test_With_Wrong_Values_Char) {
    // Arrange
    std::vector<std::string> args = { "2", "3", "b", "m" };

    // Act
    Act(args);

    // Assert
    Assert("");
}

TEST_F(HeapAppTest, Test_With_Wrong_Values_Garbage) {
    // Arrange
    std::vector<std::string> args = { "2", "3", "1", "garbage", "1" };

    // Act
    Act(args);

    // Assert
    Assert("");
}

TEST_F(HeapAppTest, Test_With_Wrong_Values_Punctuation_Marks) {
    // Arrange
    std::vector<std::string> args = { "75", "33", "!", "?", "," };

    // Act
    Act(args);

    // Assert
    Assert("");
}

TEST_F(HeapAppTest, Test_With_Correct_Values_Int) {
    // Arrange
    std::vector<std::string> args = { "87", "12", "102", "154", "91" };

    // Act
    Act(args);

    // Assert
    Assert("");
    // Assert("154 102 91 87 12");
}

TEST_F(HeapAppTest, Test_With_Correct_Values_Double) {
    // Arrange
    std::vector<std::string> args = { "14.55", "54.2", "65.3",
        "134.8", "195.0" };

    // Act
    Act(args);

    // Assert
    Assert("");
    // Assert("195 134.8 65.3 54.2 14.55");
}
