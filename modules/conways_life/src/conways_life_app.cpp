// Copyright 2022 Maksim Orlov

#include "../include/conways_life.h"
#include "../include/conways_life_app.h"

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>

void Application::help(const char* appname, const char* mes) {
    message =
        std::string(mes) +
        "This application simulates an iteration " +
        "of John Conway's Game of Life.\n\n" +
        "Please provide arguments in the following format:\n" +

        "  $ " + appname + " <grid height>" +
        " <grid width> <initial pattern bitfield>,\n" +

        " where the initial pattern bitfield is a string of 0's and 1's" +
        "corresponding to whether each cell (in the order of" +
        "left to right, top to bottom) is dead or alive.\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: should be 3 arguments!\n\n");
        return false;
    }
    return true;
}



std::vector<std::vector<bool>> parseGrid(const char* arg,
    int height, int width) {
    std::vector<std::vector<bool>> res;
    int count = 0;
    for (int i = 0; i < height; i++) {
        std::vector<bool> row;
        for (int j = 0; j < width; j++) {
            char curr = arg[count];
            if (curr == '\0') {
                throw std::string("Not enough cells!");
            } else {
                if (curr == '0') {
                    row.push_back(false);
                } else {
                    if (curr == '1') row.push_back(true);
                    else
                        throw std::string("Invalid cell");
                }
                count++;
            }
        }
        res.push_back(row);
    }
    if (arg[count] != '\0') throw std::string("Too many cells!");
    return res;
}

std::string gridToString(std::vector<std::vector<bool>> grid) {
    std::string res;
    for (unsigned int i = 0U; i < grid.size(); i++)
        for (unsigned int j = 0U; j < grid[i].size(); j++)
            if (grid[i][j]) res.push_back('1');
            else
                res.push_back('0');
    return res;
}

int stringToInt(const char* s) {
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char digit;
        res *= 10;
        digit = s[i];
        if (digit < '0' || digit > '9')
            throw std::string("Invalid dimensions!");
        else
            res += digit - '0';
    }
    return res;
}

Application::Application() {}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message;
    }
    try {
        args.height = stringToInt(argv[1]);
        args.width = stringToInt(argv[2]);
        args.grid = parseGrid(argv[3], args.height, args.width);
    } catch(std::string& str) {
        return str;
    }

    ConwaysLife field;
    field.setGrid(args.grid);
    field.nextGen(1);
    std::string res = gridToString(field.getGrid());

    return res;
}
