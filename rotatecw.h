#ifndef ROTATECW_H
#define ROTATECW_H
#include "command.h"
#include "board.h"

class RotateCW : public Command {
  Board* board;
public:
  RotateCW(Board* b); // constructor
  void execute(); // executes the rotatecw command
};

#endif
