#include <vector>
#include <string>
#include "centerblock.h"
#include "grid.h"

CenterBlock::CenterBlock(Grid* gameGrid, int blockid, int lvl, bool ob) :
level{lvl}, onBoard{ob} {
  g = gameGrid;
  cells.emplace_back(gameGrid->getCell(3,5));
  setType(type);
  setOnBoard(onBoard);
  setLeftRef(3, 5);
  set(type, blockid);
}

void CenterBlock::updateStates() {}
