#include <memory>
#include <cstdlib>
#include "l2.h"
#include "l.h"
#include "j.h"
#include "o.h"
#include "t.h"
#include "i.h"
#include "z.h"
#include "s.h"

using namespace std;

L2::L2(unsigned int seed) {
  isSeedAvailable = true;
  srand(seed);
}

L2::L2() {
  isSeedAvailable = false;
  srand(time(NULL));
}

unique_ptr<Block> L2::createBlock(Grid* grid, int id, bool onBoard, string s = "none") {
  prob = rand() % 7 + 1;
  unique_ptr<Block> b;
  if ((s == "none" && prob == 1) || s == "Z") {
    b = make_unique<Z>(grid, id, 2, onBoard);
  } else if ((s == "none" && prob == 2) || s == "S") {
    b = make_unique<S>(grid, id, 2, onBoard);
  } else if ((s == "none" && prob == 3) || s == "L") {
    b = make_unique<L>(grid, id, 2, onBoard);
  } else if ((s == "none" && prob == 4) || s == "J") {
    b = make_unique<J>(grid, id, 2, onBoard);
  } else if ((s == "none" && prob == 5) || s == "O") {
    b = make_unique<O>(grid, id, 2, onBoard);
  } else if ((s == "none" && prob == 6) || s == "T") {
    b = make_unique<T>(grid, id, 2, onBoard);
  } else if ((s == "none" && prob == 7) || s == "I") {
    b = make_unique<I>(grid, id, 2, onBoard);
  }
  return b;
}
