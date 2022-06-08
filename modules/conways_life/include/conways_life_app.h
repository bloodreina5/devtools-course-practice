// Copyright 2022 Maksim Orlov

#ifndef MODULES_CONWAYS_LIFE_INCLUDE_CONWAYS_LIFE_APP_H_
#define MODULES_CONWAYS_LIFE_INCLUDE_CONWAYS_LIFE_APP_H_

#include <include/conways_life.h>
#include <string>
#include <vector>

class Application {
 private:
    std::string message;
    typedef struct {
        int height;
        int width;
        std::vector<std::vector<bool>> grid;
    } Arguments;

    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);

 public:
    Application();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_CONWAYS_LIFE_INCLUDE_CONWAYS_LIFE_APP_H_
