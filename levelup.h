#ifndef LEVELUP_H
#define LEVELUP_H
#include <memory>

class LevelUp : public Command {
  Board* board;
public:
  LevelUp(Board* b); // constructor
  void execute(); // executes the levelup command
};

#endif
