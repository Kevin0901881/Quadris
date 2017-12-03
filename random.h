#ifndef RANDOM_H
#define RANDOM_H
#include <memory>

class Random : public Command {
  Board* board;
public:
  Random(Board* b); // constructor
  void execute(); // executes the random command
};

#endif
