// Copyright 2022 Shurygina A

#ifndef MODULES_GROSHEV_POINT_IN_TRIANGLE_INCLUDE_POINT_IN_TRIANGLE_APP_H_
#define MODULES_GROSHEV_POINT_IN_TRIANGLE_INCLUDE_POINT_IN_TRIANGLE_APP_H_
#include <string>

#include "include/point_in_triangle.h"

class PointInTriangleApplication {
 private:
bool checkArgument(const std::string& str);
int parseArgument(const char* arg);
 public:
PointInTriangleApplication();
std::string operator()(int argc, const char** argv);
std::string getHelp(const std::string& appname);
};

#endif  // MODULES_GROSHEV_POINT_IN_TRIANGLE_INCLUDE_POINT_IN_TRIANGLE_APP_H_
