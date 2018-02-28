#ifndef RESTART_H
#define RESTART_H
#include "command.h"
#include "board.h"

class Restart : public Command {
  Board* board;
public:
  Restart(Board* b); // constructor
  void execute(); // executes the restart command
};

#endif
