// Copyright 2022 Kuklin Andrey

#include "include/priority_queue_app.h"
#include "include/priority_queue.h"

#include <string.h>
#include <sstream>
#include <string>
#include <vector>

PriorityQueueApplication::PriorityQueueApplication() : app_message() {}

void PriorityQueueApplication::help(const char* appname, const char* message) {
  std::ostringstream stream;
  stream << message << "This is a priority queue application.\n\n"
         << "Please provide arguments in the following format:\n\n"
         <<

      "  $ " << appname << " <value_or_values> "
         << "<operation> <operand>\n\n"
         <<

      "Where all arguments are integer numbers, "
         << "and <operation> is one of 'push', 'pop', 'getSize', 'empty.\n\n"
         << "Use any integer nubmer for the operands with 'pop', 'getSize', "
            "'empty' operations.\n";

  app_message = stream.str();
}

bool isOnlyCharacter(const std::string& str) {
  return str.find_first_of("0123456789") == std::string::npos;
}

bool validateTypeOfArguments(int argc, const char** argv) {
  bool result = false;
  bool operationFinded = false;

  for (int i = 0; i < argc; ++i) {
    if (operationFinded) {
      if ((i + 1) == argc && !isOnlyCharacter(argv[i])) {
        result = true;
      }
    }

    if (isOnlyCharacter(argv[i])) {
      if (i + 2 == argc) {
        operationFinded = true;
      }
    }
  }

  return result;
}



bool PriorityQueueApplication::validateArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 4) {
    help(argv[0], "ERROR: Should be at least 4 arguments\n\n");
    return false;
  }

  if (!validateTypeOfArguments(argc, argv)) {
    help(argv[0]);
    return false;
  }

  return true;
}

double tryParseToInt(const char* arg) {
  int result = 0;

  try {
    result = std::stoi(arg);
  } catch (const std::invalid_argument& e) {
    throw std::string("ERROR: can't be cast to int");
  } catch (const std::out_of_range& e) {
    throw std::string("ERROR: number out of range");
  }

  return result;
}

ConsoleOperation tryParseToOperation(const char* arg) {
  ConsoleOperation operation;

  if (strcmp(arg, "push") == 0) {
    operation = ConsoleOperation::push;
  } else if (strcmp(arg, "pop") == 0) {
    operation = ConsoleOperation::pop;
  } else if (strcmp(arg, "getSize") == 0) {
    operation = ConsoleOperation::getSize;
  } else if (strcmp(arg, "empty") == 0) {
    operation = ConsoleOperation::empty;
  } else {
    throw std::string("ERROR: wrong operation");
  }

  return operation;
}

std::string PriorityQueueApplication::operator()(int argc, const char** argv) {
  if (!validateArguments(argc, argv)) {
    return app_message;
  }

  ConsoleOperation operation;
  int operand;
  std::vector<int> vectorVal;

  try {
    for (int i = 1; i < argc - 2; ++i) {
      vectorVal.push_back(tryParseToInt(argv[i]));
    }

    operation = tryParseToOperation(argv[argc - 2]);
    operand = tryParseToInt(argv[argc - 1]);
  } catch (const std::string& stringExeption) {
    return stringExeption;
  }

  std::ostringstream stream;
  PriorityQueue<int> queue(vectorVal);
  switch (operation) {
    case ConsoleOperation::push:
      queue.push(operand);
      stream << "Operand " << operand << " was pushed\n";
      break;
    case ConsoleOperation::pop:
      stream << "Element " << std::to_string(queue.pop()) << " was popped\n";
      break;
    case ConsoleOperation::getSize:
      stream << "Queue size: " << std::to_string(queue.size()) << "\n";
      break;
    case ConsoleOperation::empty:
      if (queue.isEmpty()) {
        stream << "Queue is empty\n";
      } else {
        stream << "Queue is not empty\n";
      }
      break;
  }

  app_message = stream.str();
  return app_message;
}
