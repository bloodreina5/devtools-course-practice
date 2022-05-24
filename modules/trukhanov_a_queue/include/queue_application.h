// Copyright 2022 Remizova Antonina

#ifndef MODULES_TRUKHANOV_A_QUEUE_INCLUDE_QUEUE_APPLICATION_H_
#define MODULES_TRUKHANOV_A_QUEUE_INCLUDE_QUEUE_APPLICATION_H_

#include <string>
#include <vector>
#include "include/trukhanov_a_queue.h"

enum class Operations { push, get, length };

class QueueApplication {
 public:
    QueueApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    int findOperation(int argc, const char** argv);
    bool validateNumberOfArguments(int argc, const char** argv);
    Operations parseOperation(const char* arg);
    double parseInt(const char* arg);
    std::string message_;
};

#endif  // MODULES_TRUKHANOV_A_QUEUE_INCLUDE_QUEUE_APPLICATION_H_

