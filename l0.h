#ifndef L0_H
#define L0_H
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "level.h"

class L0 : public Level {
  std::string filename; // the name of the sequence file
  std::vector<std::string> sequence; // stores the letter (block) in the order the sequence file specifies
  int sequenceSize; // stores the length of the sequence vector
  int currentBlock = 0; // gets index to the current letter (block) in the sequence vector
public:
  L0(); // constructor
  void fileReader(); // reads the letters from the sequence file
  std::unique_ptr<Block> createBlock(Grid* grid, int id, bool onBoard, std::string s); // creates a new block
};

#endif
