// Copyright 2022 Samoiluk Anastasiya

#include <string>
#include "include/figure_area_application.h"

figureArea_App::figureArea_App() : message_("") {}

void figureArea_App::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application that allows to " +
        "calculate the area of the figures\n\n" +

        "If you you want to calculate the area of a rectangle " +
        "please provide arguments in the following format:\n\n" +

        "  $ " + appname + "\n" +
        "\t<a_double_positive> <b_double_positive> <c_double_positive>\n\n" +

        "If you you want to calculate the area of a ball " +
        "please provide arguments in the following format:\n\n" +

        "  $ " + appname + "\n" +
        "\t<r_double_positive>\n";
}

bool figureArea_App::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 2 && argc != 4) {
            help(argv[0], "ERROR: Should be 1 or 3 arguments.\n\n");
            return false;
    }
    return true;
}

double figureArea_App::parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("ERROR: Wrong number format!\n");
    }

    return value;
}

std::string figureArea_App::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    double radius;
    double rect[3];
    try {
        if (argc == 2) {
            radius = parseDouble(argv[1]);
        } else {
            for (int i = 1; i < argc; i++) {
                const char* tmp = argv[i];
                rect[i - 1] = parseDouble(tmp);
            }
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    double area;
    if (argc == 2) {
        figureArea figure(radius);
        try {
            area = figure.ballArea();
            stream << "Ball area = ";
        }
        catch (std::invalid_argument const& ex) {
            stream << "ERROR: " << ex.what() << "\n";
            message_ = stream.str();
            return message_;
        }
    } else {
        figureArea figure(rect[0], rect[1], rect[2]);
        try {
            area = figure.rectangleArea();
            stream << "Rectangle area = ";
        }
        catch (std::invalid_argument const& ex) {
            stream << "ERROR: " << ex.what() << "\n";
            message_ = stream.str();
            return message_;
        }
    }

    stream << area;

    message_ = stream.str();

    return message_;
}
