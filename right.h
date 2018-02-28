#ifndef RIGHT_H
#define RIGHT_H
#include "command.h"
#include "board.h"

class Right : public Command {
  Board* board;
public:
  Right(Board* b); // constructor
  void execute(); // executes the right command
};

#endif
