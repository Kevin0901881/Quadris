#ifndef CENTERBLOCK_H
#define CENTERBLOCK_H
#include <vector>
#include <string>
#include "block.h"

class Cell;

class CenterBlock : public Block {
  int counter = 0;
  int level;
  bool onBoard = "true";
  std::string type = "*";
public:
  CenterBlock(Grid* gameGrid, int blockid, int lvl, bool onBoard);
  void updateStates();
};

#endif
