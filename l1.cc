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

L1::L1(unsigned int seed) : seed{seed} {
  isSeedAvailable = true;
}

L1::L1() {
  isSeedAvailable = false;
}

unique_ptr<Block> L1::createBlock(Grid* grid, int id, string s = "none") {
  if (isSeedAvailable) {
    srand(seed);
  } else {
    srand(time(NULL));
  }
  prob = rand() % 12 + 1;
  unique_ptr<Block> b;
  if ((string == "none" && prob == 1) || string == "Z") {
    b = make_unique<Z>(grid, id, 1);
  } else if ((string == "none" && prob == 2) || string == "S") {
    b = make_unique<S>(grid, id, 1);
  } else if ((string == "none" && (prob == 3 || prob == 4)) || string == "L") {
    b = make_unique<L>(grid, id, 1);
  } else if ((string == "none" && (prob == 5 || prob == 6)) || string == "J") {
    b = make_unique<J>(grid, id, 1);
  } else if ((string == "none" && (prob == 7 || prob == 8)) || string == "O") {
    b = make_unique<O>(grid, id, 1);
  } else if ((string == "none" && (prob == 9 || prob == 10)) || string == "T") {
    b = make_unique<T>(grid, id, 1);
  } else if ((string == "none" && (prob == 11 || prob == 12)) || string == "I") {
    b = make_unique<I>(grid, id, 1);
  }
  return b;
}
