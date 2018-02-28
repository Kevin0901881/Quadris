#include <vector>
#include <string>
#include <map>
#include "o.h"

using namespace std;

O::~O() {}
O::O(Grid* gameGrid, int blockid, int lvl, bool ob) : level{lvl}, onBoard{ob} {
  g = gameGrid;

  cells.emplace_back(gameGrid->getCell(3,0));
  cells.emplace_back(gameGrid->getCell(3,1));
  cells.emplace_back(gameGrid->getCell(4,0));
  cells.emplace_back(gameGrid->getCell(4,1));
  setWidth(2);
  setHeight(2);
  setID(blockid);
  setType(type);
  setLevel(level);
  setOnBoard(onBoard);
  setLeftRef(4, 0);
  setCurrState(0);
  setNumStates(1);
  updateStates();
  setHeaviness(); // set the heaviness of the block
  if (onBoard) { set(type, blockid); }
}

void O::updateStates() {
  // create the vector of 4 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 1});
  vec1.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row - 1, leftRef.col + 1});
  states[0] = vec1;
}
