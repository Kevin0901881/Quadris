#ifndef LEVEL_H
#define LEVEL_H
#include <memory>
#include "block.h"

class Level {
  // bool isSeedAvailable;
  // unsigned int seed;
  // int n;
public:
  // Level(int n); // constructor if there is no seed
  // Level(int n, unsigned int seed); // constructor if there is a seed
  // void setLevel(int n); // sets the current level
  // int getLevel(); // returns the current level
  virtual unique_ptr<Block> createBlock(Grid* grid, int id, std::string s = "none") = 0; // creates the next block
};

#endif
