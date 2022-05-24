// Copyright 2022 Kazhaeva Anastasia

#include "include/graph_diameter_app.h"

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>


#include "include/graph_diameter.h"


void GraphApplication::help(const char* appname, const char* mes) {
    message =
        std::string(mes) +
        "This application calculates the diameter of the graph.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <vector> <vector> ... <vector>\n\n" +
        "Where all the components of the matrix are vectors\n\n" +
        "and all vector  components are int numbers, separated by commas\n";
}

bool GraphApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        help(argv[0], "ERROR: Should be 1 arguments!\n\n");
        return false;
    }
    return true;
}

std::vector<std::vector<int>> parseVector(int argc, const char** arg) {
    std::string strI = "";
    std::vector<std::vector<int>> vec;
    char* end;
    int num;
    int ind = -1;
    for (int i = 1; i < argc; i++) {
        std::string  strVec = arg[i];
        std::vector<int > t;
        vec.push_back(t);
        ind++;
        for (unsigned int i = 0; i < strVec.size(); i++) {
            if (strVec[i] == ',') {
                if (strI == "") {
                    throw std::string("Wrong vector format!");
                }
                num = strtof(strI.c_str(), &end);
                if (end[0]) {
                    throw std::string("Wrong number format!");
                }
                vec[ind].push_back(num);
                strI = "";
            } else {
                strI += strVec[i];
            }
        }

        if (strI == "") {
            throw std::string("Wrong vector format!");
        }
        num = strtof(strI.c_str(), &end);
        if (end[0]) {
            throw std::string("Wrong number format!");
        }
        vec[ind].push_back(num);
        strI = "";
    }
    return vec;
}


GraphApplication::GraphApplication() {}

std::string GraphApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message;
    }
    try {
        args.matrix = parseVector(argc, argv);
    }
    catch (std::string& str) {
        return str;
    }

    Graph v1(args.matrix);
    std::string result = std::to_string(v1.FindDiameter());
    return result;
}
