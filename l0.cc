#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "l0.h"
#include "l.h"
#include "j.h"
#include "o.h"
#include "t.h"
#include "i.h"
#include "z.h"
#include "s.h"

using namespace std;

L0::L0() {
  filename = "sequence.txt";
  fileReader();
  currentBlock = 0;
}

void L0::fileReader() { // reads next block from a file
  ifstream infile(filename);
  string nextBlock;
  while(infile >> nextBlock) {
    sequence.emplace_back(nextBlock);
  }
  sequenceSize = sequence.size();
  infile.close();
}

unique_ptr<Block> L0::createBlock(Grid* grid, int id, bool onBoard, string s = "none") { // creates a new block
  unique_ptr<Block> b;
  if ((s == "none" && sequence.at(currentBlock) == "L") || s == "L") {
    b = make_unique<L>(grid, id, 0, onBoard);
  } else if ((s == "none" && sequence.at(currentBlock) == "J") || s == "J") {
    b = make_unique<J>(grid, id, 0, onBoard);
  } else if ((s == "none" && sequence.at(currentBlock) == "O") || s == "O") {
    b = make_unique<O>(grid, id, 0, onBoard);
  } else if ((s == "none" && sequence.at(currentBlock) == "T") || s == "T") {
    b = make_unique<T>(grid, id, 0, onBoard);
  } else if ((s == "none" && sequence.at(currentBlock) == "I") || s == "I") {
    b = make_unique<I>(grid, id, 0, onBoard);
  } else if ((s == "none" && sequence.at(currentBlock) == "Z") || s == "Z") {
    b = make_unique<Z>(grid, id, 0, onBoard);
  } else if ((s == "none" && sequence.at(currentBlock) == "S") || s == "S") {
    b = make_unique<S>(grid, id, 0, onBoard);
  }
  if (currentBlock == sequenceSize - 1) { // if currentBlock index has reached end of sequence, reset it
    currentBlock = 0;
  } else { // otherwise increment currentBlock by 1
    currentBlock++;
  }
  return b;
}
