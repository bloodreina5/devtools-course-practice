// Copyright 2022 Maksim Orlov

#include <iostream>
#include <string>
#include "../include/conways_life_app.h"

int main(int argc, const char** argv) {
    Application appl;
    std::string res = appl(argc, argv);
    std::cout << res << std::endl;
    return 0;
}
