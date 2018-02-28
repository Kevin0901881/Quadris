#ifndef HINT_H
#define HINT_H
#include "command.h"
#include "board.h"

class Hint : public Command {
  Board* board;
public:
  Hint(Board* b); // constructor
  void execute(); // executes the hint command
};

#endif
