// Copyright 2022 Kozel Svetlana
#include <iostream>

#include "include/rev_pol_app.h"

int main(int argc, const char* argv[]) {
    Application app;
    auto output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
