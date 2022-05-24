// Copyright 2022 Labinskaya Marina

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/polygon_area_app.h"

int main(int argc, const char** argv) {
    polygonAreaApp application;
    std::string out = application(argc, argv);
    std::cout << out << std::endl;
    return 0;
}
