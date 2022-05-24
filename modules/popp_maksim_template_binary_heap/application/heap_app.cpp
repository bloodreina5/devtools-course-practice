// Copyright 2022 Pyatckin Nikolay

#include <string>
#include <iostream>

#include "include/template_heap_app.h"

int main(int argc, const char** argv) {
    Heap_App App;
    std::string output = App(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
