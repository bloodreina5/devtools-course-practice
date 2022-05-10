// Copyright 2022 Pinezhanin Evgeny

#include "include/vector-distances.h"
#include "include/vector-distances_app.h"

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

void Application::help(const char* appname, const char* mes) {
    message =
        std::string(mes) +
          "This is application calculates the distance between vectors.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <vector1 components> <vector2 components>" +
          " <metric>\n\n" +

          "Where all vector components are float-precision numbers, separated" +
          " by commas and <metric> is one of Linf, L1, L2, L3, L4.\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments!\n\n");
        return false;
    }
    return true;
}

std::vector<float> parseVector(const char* arg) {
    std::string strVec = arg;
    std::string strFloat = "";
    std::vector<float> vec;
    char* end;
    float num;

    for (unsigned int i = 0; i < strVec.size(); i++) {
        if (strVec[i] == ',') {
            if (strFloat == "") {
                throw std::string("Wrong vector format!");
            }
            num = strtof(strFloat.c_str(), &end);
            if (end[0]) {
                throw std::string("Wrong number format!");
            }
            vec.push_back(num);
            strFloat = "";
        } else {
            strFloat += strVec[i];
        }
    }
    if (strFloat == "") {
        throw std::string("Wrong vector format!");
    }
    num = strtof(strFloat.c_str(), &end);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    vec.push_back(num);

    return vec;
}

int parseMetric(const char* arg) {
    std::string metric = arg;
    if (metric == "Linf") {
        return 0;
    } else if (metric == "L1") {
        return 1;
    } else if (metric == "L2") {
        return 2;
    } else if (metric == "L3") {
        return 3;
    } else if (metric == "L4") {
        return 4;
    } else {
        throw std::string("Wrong metric format!");
    }
}

Application::Application() {}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message;
    }
    try {
        args.vec1 = parseVector(argv[1]);
        args.vec2 = parseVector(argv[2]);
        args.metric = parseMetric(argv[3]);
    } catch(std::string& str) {
        return str;
    }

    Vector v1(args.vec1);
    Vector v2(args.vec2);

    std::ostringstream stream;
    stream << "p(v1, v2) = ";
    try {
        switch (args.metric) {
        case 0: stream << v1.Linf(v2) << " with metric Linf";
            break;
        case 1: case 2: case 3: case 4:
            stream << v1.L(args.metric, v2)
                << " with metric L" << args.metric;
        }
    } catch (std::string& str) {
        return str;
    }

    stream << std::endl << "v1 = (";
    for (unsigned int i = 0; i < args.vec1.size() - 1; i++) {
        stream << args.vec1[i] << ", ";
    }
    stream << args.vec1[args.vec1.size() - 1] << ")\n";
    stream << "v2 = (";
    for (unsigned int i = 0; i < args.vec2.size() - 1; i++) {
        stream << args.vec2[i] << ", ";
    }
    stream << args.vec2[args.vec2.size() - 1] << ")\n";

    message = stream.str();

    return message;
}
