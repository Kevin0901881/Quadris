#ifndef I_H
#define I_H
#include <vector>
#include <string>
#include <map>
#include "block.h"

class Cell;

class I : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 2;
  bool onBoard;
  std::string type = "I";
public:
  ~I();
  I(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
