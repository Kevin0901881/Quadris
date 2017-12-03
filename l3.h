#ifndef L3_H
#define L3_H
#include <memory>
#include <cstdlib>
#include "level.h"

class L3 : pubilc Level {
  unsigned int seed;
  int prob;
  int n;
  bool isSeedAvailable;
public:
  L3(unsigned int seed, bool isFour); // constructor with seed
  L3(bool isFour); // constructor no seed
  unique_ptr<Block> createBlock(Grid* grid, int id, std::string s); // creates a new block
};

#endif
