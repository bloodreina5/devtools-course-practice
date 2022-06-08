// Copyright 2022 Krapivenskikh Stepan

#ifndef MODULES_KAMENEV_HANOI_TOWER_INCLUDE_HANOI_TOWER_APPLICATION_H_
#define MODULES_KAMENEV_HANOI_TOWER_INCLUDE_HANOI_TOWER_APPLICATION_H_

#include <string>
#include <vector>

enum class ConsoleOperation {
  solve_hanoi,
  solve_hanoi_with_arg,
  print_all_instructions
};

class HanoiTowerApp {
 public:
  HanoiTowerApp();

  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateArguments(int argc, const char** argv);

  std::string m_message;
};

#endif  // MODULES_KAMENEV_HANOI_TOWER_INCLUDE_HANOI_TOWER_APPLICATION_H_
