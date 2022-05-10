// Copyright 2022 Soldatov Gleb

#include "include/soldatov_figure_area.h"
#include <iostream>


figureArea::figureArea() {
    this->a = 1;
    this->b = 1;
}

figureArea::figureArea(double _a) {
    this->a = _a;
}

figureArea::figureArea(double _a, double _b, double _c) {
    this->a = _a;
    this->b = _b;
    this->c = _c;
}

double figureArea::ballArea() {
    if (a <= 0.0) {
        throw std::invalid_argument("invalid parameter");
    } else {
        return (4 * PI * a * a);
    }
}

double figureArea::rectangleArea() {
    if (a <= 0.0 || b <= 0.0 || c <= 0.0) {
        throw std::invalid_argument("invalid parameters");
    } else {
        return ((2.0 * a * b) + (2.0 * a * c) + (2.0 * b * c));
    }
}
