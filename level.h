#ifndef LEVEL_H
#define LEVEL_H
#include <memory>

class Block;
class Grid;

class Level {
public:
  virtual std::unique_ptr<Block> createBlock(Grid* grid, int id, bool onBoard, std::string s = "none") = 0; // creates the next block
};

#endif
