// Copyright 2022 Remizova Antonina & Grohev Nikolay
#include <vector>
#include <string>
#include <sstream>

#include "include/remizova_a_matrix.h"
#include "include/matrix_app.h"

MatrixCalculator::MatrixCalculator() : message_("") {}

void MatrixCalculator::helpMessage(const char* message) {
  message_ = std::string(message) +
      "      This is an application which allows you \n" +
      "      to make some operations with matrix\n" +
      "      Please provide arguments in the following format:\n" +
      "      number_colunms1 number_rows1 fill_value1 \n" +
      "      number_colunms2 number_rows2 fill_value2 operation \n" +
      "      Please, use integer values \n";
}

char parseOperation(const char* arg) {
  int op;
  std::string lastArgument(arg);
  if (lastArgument == "==") {
    op = '5';
  } else if (lastArgument == "!=") {
    op = '6';
  } else if (lastArgument == "det") {
    op = '7';
  } else {
    throw std::string("Wrong operation format!");
  }
  return op;
}


bool MatrixCalculator::validateNumberOfArguments(int argc, const char** argv) {
  if (argc != 8) {
    helpMessage("Should be 7 arguments!\n\n");
    return false;
  } else {
    return true;
  }
}

int parseDouble(const char* arg) {
  char* end;
  int value = strtod(arg, &end);

  return value;
}


std::string MatrixCalculator::RunOperations(int argc, TMatrix<double> m1,
                                            TMatrix<double> m2, int operation) {
  TMatrix<int> resMatrix(2, 2);
  bool resBool;
  int resInt;
  std::string output;
  std::ostringstream stream;

  switch (operation) {
    case 53:
      resBool = m1 == m2;
      stream << "res = ";
      stream << resBool;
      break;
    case 54:
      resBool = m1 != m2;
      stream << "res = ";
      stream << resBool;
      break;
    case 55:
      resInt = m1.determinant(m2);
      stream << "res = ";
      stream << resInt;
      break;
  }

  message_ = stream.str();
  return message_;
}



std::string MatrixCalculator::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  double mtr_1_columns = parseDouble(argv[1]);
  double mtr_1_rows = parseDouble(argv[2]);
  double mtr_1_value = parseDouble(argv[3]);
  TMatrix<double> m1(mtr_1_rows, mtr_1_columns, mtr_1_value);

  double mtr_2_columns = parseDouble(argv[4]);
  double mtr_2_rows = parseDouble(argv[5]);
  double mtr_2_value = parseDouble(argv[6]);
  TMatrix<double> m2(mtr_2_rows, mtr_2_columns, mtr_2_value);
  const char* operation = argv[7];
  int oper = parseOperation(operation);
  return RunOperations(argc, m1, m2, oper);
}
