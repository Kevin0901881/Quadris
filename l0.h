#ifndef L0_H
#define L0_H
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "level.h"

class L0 : pubilc Level {
  std::string filename; // the name of the sequence file
  std::vector<std::string> sequence; // stores the letter (block) in the order the sequence file specifies
  int sequenceSize; // stores the length of the sequence vector
  int currentBlock; // gets index to the current letter (block) in the sequence vector
public:
  L0(); // constructor
  void fileReader(); // reads the letters from the sequence file
  unique_ptr<Block> createBlock(Grid* grid, int id, std::string s); // creates a new block
};

#endif
