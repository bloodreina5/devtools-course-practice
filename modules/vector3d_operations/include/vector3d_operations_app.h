// Copyright 2022 Mironova Ekaterina

#ifndef MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_OPERATIONS_APP_H_
#define MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_OPERATIONS_APP_H_

#include <string>

class Application{
 public:
    Application();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double v1_x;
        double v1_y;
        double v1_z;
        std::string operation;
        double v2_x;
        double v2_y;
        double v2_z;
    } Arguments;
};

#endif  // MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_OPERATIONS_APP_H_
