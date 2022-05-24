// Copyright 2022 Kurguzikov  Kirill

#include <iostream>
#include <string>

#include "include/cellular_state_application.h"

int main(int argc, const char* argv[]) {
    CellularStateApplication app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
