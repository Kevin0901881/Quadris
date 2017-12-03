#ifndef L2_H
#define L2_H
#include <memory>
#include <cstdlib>
#include "level.h"

class L2 : pubilc Level {
  unsigned int seed;
  int prob;
  bool isSeedAvailable;
public:
  L2(unsigned int seed); // constructor with seed
  L2(); // constructor no seed
  unique_ptr<Block> createBlock(Grid* grid, int id, std::string s); // creates a new block
};

#endif
