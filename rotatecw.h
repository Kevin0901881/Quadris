#ifndef ROTATECW_H
#define ROTATECW_H
#include <memory>

class RotateCW : public Command {
  Board* board;
public:
  RotateCW(Board* b); // constructor
  void execute(); // executes the rotatecw command
};

#endif
