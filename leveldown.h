#ifndef LEVELDOWN_H
#define LEVELDOWN_H
#include "command.h"
#include "board.h"

class LevelDown : public Command {
  Board* board;
public:
  LevelDown(Board* b); // constructor
  void execute(); // executes the leveldown command
};

#endif
