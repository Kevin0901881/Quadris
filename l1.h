#ifndef L1_H
#define L1_H
#include <memory>
#include <cstdlib>
#include "level.h"

class L1 : public Level {
  int prob;
  bool isSeedAvailable;
public:
  L1(unsigned int seed); // constructor with seed
  L1(); // constructor no seed
  std::unique_ptr<Block> createBlock(Grid* grid, int id, bool onBoard, std::string s); // creates a new block
};

#endif
