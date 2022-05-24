// Copyright 2022 Remizova Antonina
#include "include/queue_application.h"
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

QueueApplication::QueueApplication() : message_("") {}

void QueueApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application that allows to " +
        "create a queue, fill it with items " +
        "and apply some methods to the queue\n\n" +

        "To fill the queue with items " +
        "enter the first arguments in the following format:\n\n" +

        "$" + appname + "\n" +
        "\t<values_integer>\n\n" +

        "If you want to enter an operation and operand " +
        "list them after the first argument " +
        "in the following format:\n\n" +

        "$" + appname + "\n" +
        "\t<operation> <operand_integer>\n"

        "Where the operation is one of the suggested: " +
        "'push', 'get', length'\n\n";
}

int QueueApplication::findOperation(int argc, const char** argv) {
    std::vector < std::string> dop;
    std::vector < std::string>::iterator it;
    for (int i = 1; i <= argc - 1; i++)
        dop.push_back(std::string(argv[i]));
    if (std::find(dop.begin(), dop.end(), "push") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "push");
        return std::distance(dop.begin(), it) + 1;
    }

    if (std::find(dop.begin(), dop.end(), "get") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "get");
        return std::distance(dop.begin(), it) + 1;
    }

    if (std::find(dop.begin(), dop.end(), "length") != dop.end()) {
        it = std::find(dop.begin(), dop.end(), "length");
        return std::distance(dop.begin(), it) + 1;
    }

    return -1;
}

bool QueueApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        help(argv[0], "ERROR: Should be at least 3 arguments\n\n");
        return false;
    }

    if (findOperation(argc, argv) == -1) {
        help(argv[0], "ERROR: You need to enter an operation\n\n");
        return false;
    }
    return true;
}

double QueueApplication::parseInt(const char* arg) {
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

Operations QueueApplication::parseOperation(const char* arg) {
    Operations operation;

    if (strcmp(arg, "push") == 0) {
        operation = Operations::push;
    } else if (strcmp(arg, "get") == 0) {
        operation = Operations::get;
    } else if (strcmp(arg, "length") == 0) {
        operation = Operations::length;
    } else {
        throw std::string("ERROR: Wrong operation!");
    }

    return operation;
}

std::string QueueApplication::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    int size = 0;
    bool withOperand = false;

    if (findOperation(argc, argv) == argc - 1) {
        size = argc - 2;
        withOperand = false;
    } else if (findOperation(argc, argv) == argc - 2) {
        size = argc - 3;
        withOperand = true;
    }

    TQueue<int> que(size);
    Operations operation;
    int operand;

    try {
        for (int i = 1; i <= size; ++i) {
            que.Push(parseInt(argv[i]));
        }

        if (!withOperand) {
            operation = parseOperation(argv[argc - 1]);
        } else {
            operation = parseOperation(argv[argc - 2]);
            operand = parseInt(argv[argc - 1]);
        }
    }
    catch (const std::string& stringException) {
        return stringException;
    }

    std::ostringstream stream;

    switch (operation) {
    case Operations::push:
        que.Push(operand);
        stream << "queue: ";
        for (int i = 0; i < que.Length(); i++)
            stream << que[i] << " ";
        break;
    case Operations::get:
        stream << "get element: " << std::to_string(que.Get());
        break;
    case Operations::length:
        stream << "queue length: " << std::to_string(que.Length());
    }

    message_ = stream.str();
    return message_;
}
