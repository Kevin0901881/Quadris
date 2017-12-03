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

using namespace std;

L3::L3(unsigned int seed, bool isFour) : seed{seed} {
  if (isFour) {
    n = 4;
  } else {
    n = 3;
  }
  isSeedAvailable = true;
}

L3::L3(bool isFour) {
  if (isFour) {
    n = 4;
  } else {
    n = 3;
  }
  isSeedAvailable = false;
}

unique_ptr<Block> L3::createBlock(Grid* grid, int id, string s = "none") {
  if (isSeedAvailable) {
    srand(seed);
  } else {
    srand(time(NULL));
  }
  prob = rand() % 9 + 1;
  unique_ptr<Block> b;
  if ((s == "none" && (prob == 1 || prob == 2)) || s == "Z") {
    b = make_unique<Z>(grid, id, n);
  } else if ((s == "none" && (prob == 3 || prob == 4)) || s == "S") {
    b = make_unique<S>(grid, id, n);
  } else if ((s == "none" && prob == 5) || s == "L") {
    b = make_unique<L>(grid, id, n);
  } else if ((s == "none" && prob == 6) || s == "J") {
    b = make_unique<J>(grid, id, n);
  } else if ((s == "none" && prob == 7) || s == "O") {
    b = make_unique<O>(grid, id, n);
  } else if ((s == "none" && prob == 8) || s == "T") {
    b = make_unique<T>(grid, id, n);
  } else if ((s == "none" && prob == 9) || s == "I") {
    b = make_unique<I>(grid, id, n);
  } else if (s == "*") {
    b = make_unique<CenterBlock>(grid, id, 4);
  }
  return b;
}
