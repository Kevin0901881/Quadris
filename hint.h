#ifndef HINT_H
#define HINT_H
#include <memory>

class Hint : public Command {
  Board* board;
public:
  Hint(Board* b); // constructor
  void execute(); // executes the hint command
};

#endif
