// Copyright 2022 Labinskaya Marina

#include "include/polygon_area.h"
#include "include/polygon_area_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <sstream>
#include <utility>

polygonAreaApp::polygonAreaApp() {}

std::string polygonAreaApp::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return this->help(argv[0]);
    }
    if (((argc < 7) && (argc > 2)) || (argc % 2 == 0))
       return this->argument_error();

    Polygon polygon;
    std::string message;
    std::ostringstream stream;
    try {
        for (int i = 1; i < argc; i = i + 2) {
            double x, y;
            std::string v_x = argv[i];
            std::string v_y = argv[i + 1];

            x = std::stod(v_x);
            y = std::stod(v_y);
            std::pair<double, double> temp(x, y);
            polygon.addVertex(temp);
        }
        stream << polygon.countPolygonArea();
    }
    catch (std::exception const& e) {
        stream << "Invalid vertex coordinates";
    }

    message = stream.str();
    return message;
}

std::string polygonAreaApp::help(const std::string& appname) {
    std::string help = std::string("")
        + "This is a plane-polygon area counter. \n"
        + "For the correct result, enter the vertexes of the polygon \n"
        + "as follows: Enter the coordinates of the vertexes \n"
        + " counterclockwise. The x coordinate is entered first, \n"
        + " separated by a space y, and so on for all vertexes.";
    return help;
}

std::string polygonAreaApp::argument_error() {
    std::string error = std::string("")
        + "Invalid argument amount, try --help for more information";
    return error;
}
