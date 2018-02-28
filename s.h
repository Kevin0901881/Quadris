#ifndef S_H
#define S_H
#include <vector>
#include <string>
#include <map>
#include "block.h"
#include "grid.h"

class Cell;

class S : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 2;
  bool onBoard;
  std::string type = "S";
public:
  ~S();
  S(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
