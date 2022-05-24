// Copyright 2022 Kazhaeva Anastasia

#ifndef MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_
#define MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_

#include <stdexcept>
#include <string>
#include <vector>

class GraphApplication {
 public:
    GraphApplication();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message;
    typedef struct {
        std::vector<std::vector<int>> matrix;
    } Arguments;

    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_
