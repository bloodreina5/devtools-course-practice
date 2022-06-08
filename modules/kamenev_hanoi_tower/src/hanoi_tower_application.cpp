// Copyright 2022 Krapivenskikh Stepan

#include <sstream>
#include <cstring>
#include <string>
#include <vector>

#include "include/hanoi_tower.h"
#include "include/hanoi_tower_application.h"

HanoiTowerApp::HanoiTowerApp() : m_message() {}

void HanoiTowerApp::help(const char* appname,
    const char* message) {
    std::ostringstream stream;
    stream << message << "This is a hanoi tower application.\n\n"
        << "Please provide arguments in the following format:\n\n"
        <<

        "  $ " << appname << " <ringCount> "
        << "<operation> <ringCountArg> <isInstructionPrinted>\n\n";
    m_message = stream.str();
}

bool validateTypeOfArguments(int argc, const char** argv) {
    for (size_t i = 0; i < strlen(argv[1]); i++) {
        if (!std::isdigit(argv[1][i])) {
            return false;
        }
    }
    for (size_t i = 1; i < strlen(argv[2]); i++) {
        if (!std::isalpha(argv[1][i])) {
            return false;
        }
    }
    if (argc >= 4) {
        for (size_t i = 0; i < strlen(argv[3]); i++) {
            if (!std::isdigit(argv[3][i])) {
                return false;
            }
        }
        if (argc == 5) {
            for (size_t i = 0; i < strlen(argv[4]); i++) {
                if (!std::isdigit(argv[4][i])) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool HanoiTowerApp::validateArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        help(argv[0], "ERROR: Should be at least 3 arguments.\n\n");
        return false;
    }

    if (!validateTypeOfArguments(argc, argv)) {
        help(argv[0], "ERROR: Invalid type of argument.");
        return false;
    }

    return true;
}

double tryParseToInt(const char* arg) {
    int result = 0;

    try {
        result = std::stoi(arg);
    }
    catch (const std::invalid_argument& e) {
        throw std::string("ERROR: Cannot be cast to an integer!");
    }
    catch (const std::out_of_range& e) {
        throw std::string("ERROR : Number out of range!");
    }

    return result;
}

ConsoleOperation tryParseToOperation(const char* arg) {
    ConsoleOperation operation;

    if (strcmp(arg, "print_all_instructions") == 0) {
        operation = ConsoleOperation::print_all_instructions;
    } else if (strcmp(arg, "solve_hanoi") == 0) {
        operation = ConsoleOperation::solve_hanoi;
    } else if (strcmp(arg, "solve_hanoi_with_arg") == 0) {
        operation = ConsoleOperation::solve_hanoi_with_arg;
    } else {
        throw std::string("ERROR: Wrong operation!");
    }
    return operation;
}

std::string HanoiTowerApp::operator()(int argc,
    const char** argv) {
    if (!validateArguments(argc, argv)) {
        return m_message;
    }

    ConsoleOperation operation;
    int ringCount = 0;
    bool isInstructionPrinted = false;
    int ringArg = 0;
    std::string word;

    try {
        ringCount = tryParseToInt(argv[1]);
        operation = tryParseToOperation(argv[2]);
        if (argc >= 4) {
            int val = tryParseToInt(argv[3]);
            if (val == 228) {
                isInstructionPrinted = true;
            } else {
                ringArg = tryParseToInt(argv[3]);
            }
            ringArg = tryParseToInt(argv[3]);
        }
        if (argc == 5) {
            ringArg = tryParseToInt(argv[4]);
        }
    }
    catch (const std::string& stringException) {
        return stringException;
    }

    std::ostringstream stream;
    HanoiTower hanoiTower(ringCount, isInstructionPrinted);

    switch (operation) {
    case ConsoleOperation::print_all_instructions:
        hanoiTower.PrintAllInstructions();
        break;
    case ConsoleOperation::solve_hanoi:
        hanoiTower.SolveHanoi();
        break;
    case ConsoleOperation::solve_hanoi_with_arg:
        hanoiTower.SolveHanoi(ringArg);
        break;
    }

    m_message = stream.str();
    return m_message;
}
