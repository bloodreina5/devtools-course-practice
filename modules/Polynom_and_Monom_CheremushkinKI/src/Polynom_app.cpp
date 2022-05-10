// Copyright 2022 Troegubova Alexandra

#include "include/Polynom_app.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/Monom.h"
#include "include/Polynom.h"

PolynomCalculator::PolynomCalculator() : message_("") {}

void PolynomCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a polynomial calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <polynom_1> " +
        "<operation> <polynom_2>\n\n" +

        "Where <operation> is one of '+', '-', '*', '/', " +
        " and the polynomials correspond to the following format : \n\n" +

        "<coeff_1>x**<deg_1><'+' or '-'><coeff_2>x**<deg_2><'+' or '-'>ets\n" +
        "Where all coefficients and degrees of monomials are " +
        "double - precision numbers, and there should be no spaces " +
        "in the polynomial record.\n" + "Example of arguments:\n\n" +
        "  $ " + appname + " 5x^2+6x^1+1x^0 * 1x^9-3x^2.\n";
}

bool PolynomCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

void addMonom(Monom* p, const Monom& new_m) {
    if (p->GetNextMonom() != NULL) {
        addMonom(p->GetNextMonom(), new_m);
    } else {
        p->SetNextMonom(new_m);
    }
}

Polynom parsePolynom(const char* arg) {
    int size = 1;
    Polynom p(size);
    char* end = strdup(arg);

    double coeff;
    int deg;
    coeff = strtod(end, &end);
    const char tmp[] = { end[0], end[1], '\0'};
    if (strcmp(tmp, "x^") != 0) {
        throw std::string("Wrong polynomial format!");
    }
    deg = static_cast<int>(strtod(end + 2, &end));
    Monom m(coeff, deg);

    p.GetStartMonom()->SetCoef(m.GetCoef());
    p.GetStartMonom()->SetDegree(m.GetDegree());
    while (end[0]) {
        coeff = strtod(end, &end);
        const char tmp[] = { end[0], end[1], '\0' };
        if (strcmp(tmp, "x^") != 0) {
            throw std::string("Wrong polynomial format!");
        }
        deg = static_cast<int>(strtod(end + 2, &end));
        m.SetCoef(coeff);
        m.SetDegree(deg);
        addMonom(p.GetStartMonom(), m);
        size++;
    }
    p.SetSize(size);
    return p;
}

std::string PolynomCalculator::operator()
(int argc, const char** argv) {
    Arguments args;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.polynom_1 = parsePolynom(argv[1]);
        args.operation = parseOperation(argv[2]);
        args.polynom_2 = parsePolynom(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    Polynom res;

    switch (args.operation) {
    case '+':
        res = args.polynom_1 + args.polynom_2;
        stream << args.polynom_1.StrPolynom() << "  +  " <<
            args.polynom_2.StrPolynom() << "  =  " << res.StrPolynom();
        break;
    case '-':
        res = args.polynom_1 - args.polynom_2;
        stream << args.polynom_1.StrPolynom() << "  -  " <<
            args.polynom_2.StrPolynom() << "  =  " << res.StrPolynom();
        break;
    case '*':
        res = args.polynom_1 * args.polynom_2;
        stream << args.polynom_1.StrPolynom() << "  *  " <<
            args.polynom_2.StrPolynom() << "  =  " << res.StrPolynom();
        break;
    case '/':
        try {
            res = args.polynom_1 / args.polynom_2;
            stream << args.polynom_1.StrPolynom() << "  /  " <<
                args.polynom_2.StrPolynom() << "  =  " << res.StrPolynom();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
