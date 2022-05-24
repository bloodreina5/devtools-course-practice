// Copyright 2022 Petrova Polina


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "../include/numeric_interval.h"
#include "../include/numeric_interval_app.h"

Application::Application() : message_(""), op(0) {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is application works with numeric intervals. \n\n" +
        "There all formats, you can write:\n" +
        "\t 'contain_a' <range> <int_size> <values> - Is range contain an " +
        "integer interval?\n" +
        "\t 'all_p' <range> - Get all points in range\n" +
        "\t 'contain_r' <range_1> <range_2> - Is range contain another " +
        "range?\n" +
        "\t 'end_p' <range> - Get end points of range\n" +
        "\t 'overlap' <range_1> <range_2> - "+
        "Is range overlaps another range?\n" +
        "\t 'equal' <range_1> <range_2> - Do they equal?\n\n";
}

int parseInt(const char* arg) {
    int i = 0;
    while (arg[i] != '\0') {
        if (!isdigit(arg[i++]))
            throw std::string("Wrong number format!");
    }
    return atoi(arg);
}

int Application::parseOperation(const char* arg, int argc) {
    int op;
    if ((strcmp(arg, "contain_a") == 0)) {
        if (argc < 4)
            throw std::string("ERROR: Must be 3 args for contain_a");
        op = 0;
    } else if (strcmp(arg, "all_p") == 0) {
        if (argc != 3)
            throw std::string("ERROR: Must be 2 args for all_p");
        op = 1;
    } else if (strcmp(arg, "contain_r") == 0) {
        if (argc != 4)
            throw std::string("ERROR: Must be 3 args for contain_r");
        op = 2;
    } else if (strcmp(arg, "end_p") == 0) {
        if (argc != 3)
            throw std::string("ERROR: Must be 2 args for end_p");
        op = 3;
    } else if (strcmp(arg, "overlap") == 0) {
        if (argc != 4)
            throw std::string("ERROR: Must be 3 args for overlap");
        op = 4;
    } else if (strcmp(arg, "equal") == 0) {
        if (argc != 4)
            throw std::string("ERROR: Must be 3 args for equal");
        op = 5;
    } else {
        throw std::string("Wrong operation format!");
    }

    return op;
}

std::string Application::operator()(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return message_;
    }

    try {
        op = parseOperation(argv[1], argc);
    }
    catch (std::string& str) {
        return str;
    }

    NamericInterval r(argv[2]);
    std::ostringstream stream;

    switch (op) {
    case 0:
        int len;
        int* arr;

        try {
            len = parseInt(argv[3]);
            arr = new int[len];
            for (int i = 0; i < len; i++) {
                arr[i] = parseInt(argv[i + 4]);
            }
        }
        catch (std::string& str) {
            return str;
        }

        if (r.IntegerRangeContains(arr, len))
            stream << "TRUE";
        else
            stream << "FALSE";

        delete[] arr;
        break;
    case 1:
        stream << r.GetAllPoints();
        break;

    case 2:
        if (r.ContainsRange(argv[3]))
            stream << "TRUE";
        else
            stream << "FALSE";
        break;

    case 3:
        stream << r.EndPoints();
        break;

    case 4:
        if (r.OverlapsRange(argv[3]))
            stream << "TRUE";
        else
            stream << "FALSE";
        break;

    case 5:
        NamericInterval r1(argv[3]);

        if (r == r1)
            stream << "TRUE";
        else
            stream << "FALSE";
        break;
    }

    message_ = stream.str();

    return message_;
}
