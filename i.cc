#include <vector>
#include <map>
#include <string>
#include "i.h"
#include "grid.h"
#include "cell.h"

using namespace std;

I::~I() {}
I::I(Grid* gameGrid, int blockid, int lvl, bool ob) : level{lvl}, onBoard{ob} {
  g = gameGrid;
  // create original cells vector
  cells.emplace_back(gameGrid->getCell(3,0));
  cells.emplace_back(gameGrid->getCell(3,1));
  cells.emplace_back(gameGrid->getCell(3,2));
  cells.emplace_back(gameGrid->getCell(3,3));
  setWidth(4);
  setHeight(1);
  setID(blockid);
  setType(type);
  setLevel(level);
  setOnBoard(onBoard);
  setLeftRef(3, 0);
  setCurrState(0);
  setNumStates(2);
  updateStates(); // create the vector of states
  setHeaviness(); // set the heaviness of this block
  if (onBoard) { set(type, blockid); }
}

void I::updateStates() {
  // create the vector of 2 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 1});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 2});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 3});
  states[0] = vec1;

  // State 1 (CW once from State 0)
  vector<Coordinate> vec2;
  vec2.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 2, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 3, leftRef.col});
  states[1] = vec2;
}
