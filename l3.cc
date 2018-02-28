#include <memory>
#include <cstdlib>
#include "l3.h"
#include "l.h"
#include "j.h"
#include "o.h"
#include "t.h"
#include "i.h"
#include "z.h"
#include "s.h"
#include "centerblock.h"

using namespace std;

L3::L3(bool isFour, string sf) : filename{sf} {
  if (isFour) {
    n = 4;
  } else {
    n = 3;
  }
  noRandom = true;
  isSeedAvailable = false;
  srand(time(NULL));
  fileReader();
  sequenceSize = sequence.size();
}

L3::L3(unsigned int seed, bool isFour) {
  if (isFour) {
    n = 4;
  } else {
    n = 3;
  }
  noRandom = false;
  isSeedAvailable = true;
  srand(seed);
}

L3::L3(bool isFour) {
  if (isFour) {
    n = 4;
  } else {
    n = 3;
  }
  noRandom = false;
  isSeedAvailable = false;
  srand(time(NULL));
}

void L3::fileReader() { // reads next block from a file
  ifstream infile(filename);
  string nextBlock;
  while(infile >> nextBlock) {
    sequence.emplace_back(nextBlock);
  }
  infile.close();
}

unique_ptr<Block> L3::createBlock(Grid* grid, int id, bool onBoard, string s = "none") {
  unique_ptr<Block> b;
  if (noRandom) {
    if ((s == "none" && sequence.at(currentBlock) == "L") || s == "L") {
      b = make_unique<L>(grid, id, n, onBoard);
    } else if ((s == "none" && sequence.at(currentBlock) == "J") || s == "J") {
      b = make_unique<J>(grid, id, n, onBoard);
    } else if ((s == "none" && sequence.at(currentBlock) == "O") || s == "O") {
      b = make_unique<O>(grid, id, n, onBoard);
    } else if ((s == "none" && sequence.at(currentBlock) == "T") || s == "T") {
      b = make_unique<T>(grid, id, n, onBoard);
    } else if ((s == "none" && sequence.at(currentBlock) == "I") || s == "I") {
      b = make_unique<I>(grid, id, n, onBoard);
    } else if ((s == "none" && sequence.at(currentBlock) == "Z") || s == "Z") {
      b = make_unique<Z>(grid, id, n, onBoard);
    } else if ((s == "none" && sequence.at(currentBlock) == "S") || s == "S") {
      b = make_unique<S>(grid, id, n, onBoard);
    }
    if (currentBlock == sequenceSize) { // if currentBlock index has reached end of sequence, reset it
      currentBlock = 0;
    } else { // otherwise increment currentBlock by 1
      currentBlock++;
    }
  } else {
    prob = rand() % 9 + 1;

    if ((s == "none" && (prob == 1 || prob == 2)) || s == "Z") {
      b = make_unique<Z>(grid, id, n, onBoard);
    } else if ((s == "none" && (prob == 3 || prob == 4)) || s == "S") {
      b = make_unique<S>(grid, id, n, onBoard);
    } else if ((s == "none" && prob == 5) || s == "L") {
      b = make_unique<L>(grid, id, n, onBoard);
    } else if ((s == "none" && prob == 6) || s == "J") {
      b = make_unique<J>(grid, id, n, onBoard);
    } else if ((s == "none" && prob == 7) || s == "O") {
      b = make_unique<O>(grid, id, n, onBoard);
    } else if ((s == "none" && prob == 8) || s == "T") {
      b = make_unique<T>(grid, id, n, onBoard);
    } else if ((s == "none" && prob == 9) || s == "I") {
      b = make_unique<I>(grid, id, n, onBoard);
    } else if (s == "*") {
      b = make_unique<CenterBlock>(grid, id, 4, true);
    }
  }
  return b;
}
