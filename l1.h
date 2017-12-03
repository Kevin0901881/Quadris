#ifndef L1_H
#define L1_H
#include <memory>
#include <cstdlib>
#include "level.h"

class L1 : pubilc Level {
  unsigned int seed;
  int prob;
  bool isSeedAvailable;
public:
  L1(unsigned int seed); // constructor with seed
  L1(); // constructor no seed
  unique_ptr<Block> createBlock(Grid* grid, int id, std::string s); // creates a new block
};

#endif
