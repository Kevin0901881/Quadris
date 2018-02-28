#ifndef O_H
#define O_H
#include <vector>
#include <map>
#include <string>
#include "block.h"
#include "grid.h"

class Cell;

class O : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 1;
  bool onBoard;
  std::string type = "O";
public:
  ~O();
  O(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
