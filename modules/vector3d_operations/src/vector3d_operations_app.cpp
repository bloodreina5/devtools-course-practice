// Copyright 2022 Mironova Ekaterina

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "include/vector3d_operations.h"
#include "include/vector3d_operations_app.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application which can do operations with 3d vectors\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " v1_x v1_y v1_z " +
        "<operation> v2_x v2_y v2_z (if use 2 vectors)\n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of 'get_norm', 'get_normalization' " +
        "(for 1 vector), 'scalar_mult', 'vector_mult' (for 2 vectors).\n";
}

bool  Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    if ((argc != 5) && (argc != 8)) {
        help(argv[0], "ERROR: Should be 4 or 7 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "get_norm") == 0) {
        op = "get_norm";
    } else if (strcmp(arg, "get_normalization") == 0) {
        op = "get_normalization";
    } else if (strcmp(arg, "scalar_mult") == 0) {
        op = "scalar_mult";
    } else if (strcmp(arg, "vector_mult") == 0) {
        op = "vector_mult";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.v1_x = parseDouble(argv[1]);
        args.v1_y = parseDouble(argv[2]);
        args.v1_z = parseDouble(argv[3]);
        args.operation = parseOperation(argv[4]);
        if (argc > 5)
            args.v2_x = parseDouble(argv[5]);
        else
            args.v2_x = 0;
        if (argc > 6)
            args.v2_y = parseDouble(argv[6]);
        else
            args.v2_y = 0;
        if (argc > 7)
            args.v2_z = parseDouble(argv[7]);
        else
            args.v2_z = 0;
    }
    catch (std::string& str) {
        return str;
    }
    Vector3d v1(args.v1_x, args.v1_y, args.v1_z);
    Vector3d v2(args.v2_x, args.v2_y, args.v2_z);
    Vector3d res_vector;
    double res;
    std::ostringstream stream;
    if (args.operation == "get_norm") {
        res = v1.get_norm();
        stream << "Norm = " << res;
    }
    if (args.operation == "get_normalization") {
        try {
            res_vector = v1.get_normalization();
            stream << "V = (" << res_vector[0] << "," << res_vector[1]
                << "," << res_vector[2] << ")";
        }
        catch (const std::exception& e) {
            return e.what();
        }
    }
    if (args.operation == "scalar_mult") {
        res = v1.scalar_mult(v1, v2);
        stream << "Scalar_mult = " << res;
    }
    if (args.operation == "vector_mult") {
        res_vector = v1.vector_mult(v1, v2);
        stream << "V = (" << res_vector[0] << "," << res_vector[1]
            << "," << res_vector[2] << ")";
    }
    message_ = stream.str();

    return message_;
}
