#ifndef J_H
#define J_H
#include <vector>
#include <string>
#include <map>
#include "block.h"
#include "grid.h"

class Cell;

class J : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 4;
  bool onBoard;
  std::string type = "J";
public:
  ~J();
  J(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
