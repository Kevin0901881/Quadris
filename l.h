#ifndef L_H
#define L_H
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "block.h"
#include "grid.h"

class Cell;

class L : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 4;
  int heaviness;
  bool onBoard;
  std::string type = "L";
public:
  ~L();
  L(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
