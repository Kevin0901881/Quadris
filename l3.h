#ifndef L3_H
#define L3_H
#include <vector>
#include <memory>
#include <cstdlib>
#include <string>
#include <fstream>
#include "level.h"

class L3 : public Level {
  int prob;
  int n;
  bool isSeedAvailable;
  bool noRandom = false;
  std::string filename;
  std::vector<std::string> sequence; // stores the letter (block) in the order the sequence file specifies
  int sequenceSize;
  int currentBlock;
public:
  L3(bool isFour, std::string sf);
  L3(unsigned int seed, bool isFour); // constructor with seed
  L3(bool isFour); // constructor no seed
  void fileReader(); // reads the letters from the sequence file
  std::unique_ptr<Block> createBlock(Grid* grid, int id, bool onBoard, std::string s); // creates a new block
};

#endif
