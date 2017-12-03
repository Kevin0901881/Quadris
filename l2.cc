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

L2::L2(unsigned int seed) : seed{seed} {
  isSeedAvailable = true;
}

L2::L2() {
  isSeedAvailable = false;
}

unique_ptr<Block> L2::createBlock(Grid* grid, int id, string s = "none") {
  if (isSeedAvailable) {
    srand(seed);
  } else {
    srand(time(NULL));
  }
  prob = rand() % 7 + 1;
  unique_ptr<Block> b;
  if ((string == "none" && prob == 1) || string == "Z") {
    b = make_unique<Z>(grid, id, 2);
  } else if ((string == "none" && prob == 2) || string == "S") {
    b = make_unique<S>(grid, id, 2);
  } else if ((string == "none" && prob == 3) || string == "L") {
    b = make_unique<L>(grid, id, 2);
  } else if ((string == "none" && prob == 4) || string == "J") {
    b = make_unique<J>(grid, id, 2);
  } else if ((string == "none" && prob == 5) || string == "O") {
    b = make_unique<O>(grid, id, 2);
  } else if ((string == "none" && prob == 6) || string == "T") {
    b = make_unique<T>(grid, id, 2);
  } else if ((string == "none" && prob == 7) || string == "I") {
    b = make_unique<I>(grid, id, 2);
  }
  return b;
}
