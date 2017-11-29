#ifndef O_H
#define O_H
#include <vector>
#include "block.h"

class Cell;

class O : public Block {
  vector<Cell*> cells;
  int counter = 0;
  int level;
public:
  ~O();
  void init() override;
  void rotateCW() override;
  void rotateCCW() override;
};

#endif
