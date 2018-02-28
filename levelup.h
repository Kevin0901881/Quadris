#ifndef LEVELUP_H
#define LEVELUP_H
#include "command.h"
#include "board.h"

class LevelUp : public Command {
  Board* board;
public:
  LevelUp(Board* b); // constructor
  void execute(); // executes the levelup command
};

#endif
