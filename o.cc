#include <vector>
#include "o.h"

using namespace std;

O::~O() {}

void O::init(Board* b, int lvl) {
  // (0,3), (1,3), (0,4), (1,4)
  Cell* c1 = b->getCell(0,3);
  cells.emplace_back(c1);
  Cell* c2 = b->getCell(1,3);
  cells.emplace_back(c2);
  Cell* c3 = b->getCell(0,4);
  cells.emplace_back(c3);
  Cell* c4 = b->getCell(1,4);
  cells.emplace_back(c4);
  level = lvl;
}

void O::rotateCW() {
}

void O::rotateCCW() {
}
