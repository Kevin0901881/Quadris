#ifndef DOWN_H
#define DOWN_H
#include <memory>

class Down : public Command {
  Board* board;
public:
  Down(Board* b); // constructor
  void execute(); // executes the down command
};

#endif
