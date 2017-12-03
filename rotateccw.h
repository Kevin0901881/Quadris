#ifndef ROTATECCW_H
#define ROTATECCW_H
#include <memory>

class RotateCCW : public Command {
  Board* board;
public:
  RotateCCW(Board* b); // constructor
  void execute(); // executes the rotateccw command
};

#endif
