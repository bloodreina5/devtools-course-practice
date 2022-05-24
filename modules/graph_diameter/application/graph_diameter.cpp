// Copyright 2022 Kazhaeva Anastasia

#include <iostream>
#include <string>

#include "include/graph_diameter_app.h"

int main(int argc, const char** argv) {
GraphApplication app;
auto result = app(argc, argv);
std::cout << result << std::endl;
return 0;
}
