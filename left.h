#ifndef LEFT_H
#define LEFT_H

class Left : public Command {
  Board* board;
public:
  Left(Board* b); // constructor
  void execute(); // executes the left command
};

#endif
