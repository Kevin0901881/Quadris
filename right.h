#ifndef RIGHT_H
#define RIGHT_H
#include <memory>

class Right : public Command {
  Board* board;
public:
  Right(Board* b); // constructor
  void execute(); // executes the right command
};

#endif
