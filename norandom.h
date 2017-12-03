#ifndef NORANDOM_H
#define NORANDOM_H
#include <string>
#include <memory>

class NoRandom : public Command {
  Board* board;
  std::string scriptfile;
public:
  NoRandom(Board* b, std::string scriptfile); // constructor
  void execute(); // executes the norandom command
};

#endif
