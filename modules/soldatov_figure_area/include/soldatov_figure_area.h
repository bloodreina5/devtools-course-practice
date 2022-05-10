// Copyright 2022 Soldatov Gleb

#ifndef MODULES_SOLDATOV_FIGURE_AREA_INCLUDE_SOLDATOV_FIGURE_AREA_H_
#define MODULES_SOLDATOV_FIGURE_AREA_INCLUDE_SOLDATOV_FIGURE_AREA_H_
const double PI = 3.1415;


class figureArea {
 private:
    double a, b, c;
 public:
    figureArea();
    explicit figureArea(double _a);
    figureArea(double _a, double _b, double _c);
    double ballArea();
    double rectangleArea();
};

#endif  // MODULES_SOLDATOV_FIGURE_AREA_INCLUDE_SOLDATOV_FIGURE_AREA_H_
