// Copyright 2022 Shurygina A

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/point_in_triangle_app.h"

int main(int argc, const char** argv) {
    PointInTriangleApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
