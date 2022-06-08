// Copyright 2022 Soldatov Gleb

#include <string>
#include "include/combinations_application.h"

combinations_App::combinations_App() : message_("") {}

void combinations_App::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application that allows to " +
        "generate all possible combinations of K array elements\n\n" +

        "If you you want to generate combination" +
        "provide arguments in the following format:\n\n" +

        "  $ " + appname + "\n" +
        "\t<n_int_positive> <m_int_positive>\n";
}

bool combinations_App::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

double combinations_App::parseDouble(const char* arg) {
    char* end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("ERROR: Wrong number format!\n");
    }

    return value;
}

std::string combinations_App::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    double arguments[2];
    try {
        for (int i = 1; i < argc; i++) {
            const char* tmp = argv[i];
            arguments[i - 1] = parseDouble(tmp);
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    int result;
    combinations cmb(arguments[0], arguments[1]);
    try {
        result = cmb.get_cnm();
        stream << "Amount of combinations = ";
        }
    catch (std::invalid_argument const& ex) {
        stream << "ERROR: " << ex.what() << "\n";
        message_ = stream.str();
        return message_;
    }

    stream << result;

    message_ = stream.str();

    return message_;
}
