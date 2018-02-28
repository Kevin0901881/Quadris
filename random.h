#ifndef RANDOM_H
#define RANDOM_H
#include "command.h"

class Board;

class Random : public Command {
  Board* board;
public:
  Random(Board* b); // constructor
  void execute(); // executes the random command
};

#endif
