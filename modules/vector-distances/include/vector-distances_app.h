// Copyright 2022 Pinezhanin Evgeny

#ifndef MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_APP_H_
#define MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_APP_H_

#include <string>
#include <vector>

class Application {
 private:
    std::string message;
    typedef struct {
        std::vector<float> vec1;
        std::vector<float> vec2;
        int metric;
    } Arguments;

    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);

 public:
    Application();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_APP_H_
