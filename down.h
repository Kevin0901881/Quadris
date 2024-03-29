#ifndef DOWN_H
#define DOWN_H
#include "command.h"
#include "board.h"

class Down : public Command {
  Board* board;
public:
  Down(Board* b); // constructor
  void execute(); // executes the down command
};

#endif
