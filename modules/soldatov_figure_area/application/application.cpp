// Copyright 2022 Samoiluk Anastasiya

#include <iostream>
#include <string>
#include "include/figure_area_application.h"

int main(int argc, const char** argv) {
    figureArea_App app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
