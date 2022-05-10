// Copyright 2022 Kamenev Ilya

#include <gtest/gtest.h>

#include "./include/hanoi_tower.h"

TEST(HanoiTower, DefaultCtorTest) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(HanoiTower tower);
}

TEST(HanoiTower, CtorTest) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(HanoiTower(5));
}

TEST(HanoiTower, CtorActivePrintTest) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(HanoiTower(5, true));
}

TEST(HanoiTower, CreatedTowerFromTest) {
  // Arrange,
  HanoiTower tower(5);
  // Act, Assert
  EXPECT_EQ(tower.GetColSize(1), 5);
}

TEST(HanoiTower, CreatedTowerToTest) {
  // Arrange,
  HanoiTower tower(5);
  // Act, Assert
  EXPECT_EQ(tower.GetColSize(2), 0);
}

TEST(HanoiTower, CreatedTowerBufTest) {
  // Arrange,
  HanoiTower tower(5);
  // Act, Assert
  EXPECT_EQ(tower.GetColSize(3), 0);
}

TEST(HanoiTower, SolveHanoiFromTest) {
  // Arrange
  HanoiTower tower(5);
  // Act
  tower.SolveHanoi();
  // Assert
  EXPECT_EQ(tower.GetColSize(1), 0);
}

TEST(HanoiTower, SolveHanoiToTest) {
  // Arrange
  HanoiTower tower(5);
  // Act
  tower.SolveHanoi();
  // Assert
  EXPECT_EQ(tower.GetColSize(2), 5);
}

TEST(HanoiTower, SolveHanoiBufTest) {
  // Arrange
  HanoiTower tower(5);
  // Act
  tower.SolveHanoi();
  // Assert
  EXPECT_EQ(tower.GetColSize(3), 0);
}

TEST(HanoiTower, SolveHanoiWithParamFromTest) {
  // Arrange
  HanoiTower tower(5);
  // Act
  tower.SolveHanoi(5);
  // Assert
  EXPECT_EQ(tower.GetColSize(1), 0);
}

TEST(HanoiTower, SolveHanoiWithParamToTest) {
  // Arrange
  HanoiTower tower;
  // Act
  tower.SolveHanoi(5);
  // Assert
  EXPECT_EQ(tower.GetColSize(2), 5);
}

TEST(HanoiTower, SolveHanoiWithParamBufTest) {
  // Arrange
  HanoiTower tower;
  // Act
  tower.SolveHanoi(5);
  // Assert
  EXPECT_EQ(tower.GetColSize(3), 0);
}

TEST(HanoiTower, SolveHanoiSomeCallsFromTest) {
  // Arrange
  HanoiTower tower(3);
  // Act
  tower.SolveHanoi();
  tower.SolveHanoi(5);
  // Assert
  EXPECT_EQ(tower.GetColSize(1), 0);
}

TEST(HanoiTower, SolveHanoiSomeCallsToTest) {
  // Arrange
  HanoiTower tower(3);
  // Act
  tower.SolveHanoi();
  tower.SolveHanoi(5);
  // Assert
  EXPECT_EQ(tower.GetColSize(2), 5);
}

TEST(HanoiTower, SolveHanoiSomeCallsBufTest) {
  // Arrange
  HanoiTower tower(3);
  // Act
  tower.SolveHanoi();
  tower.SolveHanoi(5);
  // Assert
  EXPECT_EQ(tower.GetColSize(3), 0);
}

TEST(HanoiTower, SolveHanoiWithPrintingInstructionsTest) {
  // Arrange
  HanoiTower tower(5, true);
  // Act, Assert
  ASSERT_NO_THROW(tower.SolveHanoi());
}

TEST(HanoiTower, WrongRingCountValueTest) {
  // Arrange
  HanoiTower tower;
  // Act, Assert
  ASSERT_NO_THROW(tower.SolveHanoi(-5));
}

TEST(HanoiTower, PrintAllInstructionsTest) {
  // Arrange
  HanoiTower tower(5);
  // Act
  tower.SolveHanoi();
  // Assert
  ASSERT_NO_THROW(tower.PrintAllInstructions());
}

TEST(HanoiTower, WrongColNumValueTest) {
  // Arrange
  HanoiTower tower(5);
  // Act
  tower.SolveHanoi();
  // Assert
  EXPECT_EQ(tower.GetColSize(4), 0);
}
