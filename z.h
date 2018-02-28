#ifndef Z_H
#define Z_H
#include <vector>
#include <string>
#include <map>
#include "block.h"
#include "grid.h"

class Cell;

class Z : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 2;
  int width = 3;
  int height = 2;
  bool onBoard;
  std::string type = "Z";
public:
  ~Z();
  Z(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
