#include <memory>
#include <cstdlib>
#include "l1.h"
#include "l.h"
#include "j.h"
#include "o.h"
#include "t.h"
#include "i.h"
#include "z.h"
#include "s.h"

using namespace std;

L1::L1(unsigned int seed) {
  isSeedAvailable = true;
  srand(seed);
}

L1::L1() {
  isSeedAvailable = false;
  srand(time(NULL));
}

unique_ptr<Block> L1::createBlock(Grid* grid, int id, bool onBoard, string s = "none") {
  prob = rand() % 12 + 1;
  cout << prob << endl;
  unique_ptr<Block> b;
  if ((s == "none" && prob == 1) || s == "Z") {
    b = make_unique<Z>(grid, id, 1, onBoard);
  } else if ((s == "none" && prob == 2) || s == "S") {
    b = make_unique<S>(grid, id, 1, onBoard);
  } else if ((s == "none" && (prob == 3 || prob == 4)) || s == "L") {
    b = make_unique<L>(grid, id, 1, onBoard);
  } else if ((s == "none" && (prob == 5 || prob == 6)) || s == "J") {
    b = make_unique<J>(grid, id, 1, onBoard);
  } else if ((s == "none" && (prob == 7 || prob == 8)) || s == "O") {
    b = make_unique<O>(grid, id, 1, onBoard);
  } else if ((s == "none" && (prob == 9 || prob == 10)) || s == "T") {
    b = make_unique<T>(grid, id, 1, onBoard);
  } else if ((s == "none" && (prob == 11 || prob == 12)) || s == "I") {
    b = make_unique<I>(grid, id, 1, onBoard);
  }
  return b;
}
