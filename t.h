#ifndef T_H
#define T_H
#include <vector>
#include <string>
#include <map>
#include "block.h"
#include "grid.h"

class Cell;

class T : public Block {
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 4;
  bool onBoard;
  std::string type = "T";
public:
  ~T();
  T(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
