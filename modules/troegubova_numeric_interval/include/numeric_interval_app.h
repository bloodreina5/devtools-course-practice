// Copyright 2022 Petrova Polina

#ifndef MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_APP_H_
#define MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_APP_H_

#include <string>
#include <vector>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
    int parseOperation(const char* arg, int argc);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
    int op;
};

#endif  // MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_APP_H_
