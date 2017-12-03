#ifndef LEVELDOWN_H
#define LEVELDOWN_H
#include <memory>

class LevelDown : public Command {
  Board* board;
public:
  LevelDown(Board* b); // constructor
  void execute(); // executes the leveldown command
};

#endif
