// Copyright 2022 Kuklin Andrey

#ifndef MODULES_ZAITSEVA_K_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
#define MODULES_ZAITSEVA_K_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_

#include <string>

enum class ConsoleOperation { push, pop, getSize, empty };

class PriorityQueueApplication {
 public:
  PriorityQueueApplication();

  std::string operator()(int argc, const char** argv);

 private:
  std::string app_message;

  void help(const char* appname, const char* message = "");
  bool validateArguments(int argc, const char** argv);
};

#endif  // MODULES_ZAITSEVA_K_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
