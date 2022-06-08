// Copyright 2022 Javier Galindo

#include <cstring>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "include/rb_tree_app.h"

std::string RBTreeApp::Help(const char* appname) {
    return "This is application for rbtree class\n" \
        "Usage:\n" \
        "> " + std::string(appname) + " actions that described below\n" \
        "Actions:\n" \
        "insert <value> - add value to the tree\n" \
        "remove <value> - delete value from the tree\n" \
        "find <value> - find the value in the tree\n";
}

std::string RBTreeApp::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return Help(*argv);
    }
    try {
        for (int i = 1; i < argc; ) {
            int offset = ParseOperation(argv + i);
            i += offset;
        }
        return out_.str();
    }
    catch (std::runtime_error& re) {
        return re.what();
    }
}

int RBTreeApp::ParseNumber(const char* s) {
    int len = std::strlen(s);
    if ((s[0] != '-' && !isdigit(s[0])) || (s[0] == '-' && len == 1))
        throw std::runtime_error(std::string(s) + " is not the number");
    for (int i = 1; i < len; ++i)
        if (!isdigit(s[i]))
            throw std::runtime_error(std::string(s) + " is not the number");
    int64_t result = std::strtol(s, nullptr, 10);
    if (result <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
        result >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
        throw std::runtime_error("Number is out of bounds");
    }
    return static_cast<int>(result);
}

int RBTreeApp::ParseOperation(const char** argv) {
    if (strcmp(*argv, "insert") == 0) {
        int value = ParseNumber(*(argv + 1));
        Node* sos = new Node(value);
        t_.insert(sos);
        return 2;
    }
    if (strcmp(*argv, "remove") == 0) {
        int value = ParseNumber(*(argv + 1));
        t_.remove(value);
        return 2;
    }
    if (strcmp(*argv, "find") == 0) {
        int value = ParseNumber(*(argv + 1));
        bool verdict = t_.find(value);
        if (verdict)
            out_ << "(" << value << " is found) ";
        else
            out_ << "(" << value << " is not found) ";
        return 2;
    }
    throw std::runtime_error(std::string("Unknown operation: ") +
        std::string(*argv));
    return 0;
}
