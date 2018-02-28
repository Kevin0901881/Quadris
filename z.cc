#include <vector>
#include <map>
#include <string>
#include "z.h"

using namespace std;

Z::~Z() {}
Z::Z(Grid* gameGrid, int blockid, int lvl, bool ob) : level{lvl}, onBoard{ob} {
  g = gameGrid;

  // // create orginal cells vector
  cells.emplace_back(gameGrid->getCell(3,0));
  cells.emplace_back(gameGrid->getCell(3,1));
  cells.emplace_back(gameGrid->getCell(4,1));
  cells.emplace_back(gameGrid->getCell(4,2));
  setWidth(3);
  setHeight(2);
  setID(blockid);
  setType(type);
  setLevel(level);
  setOnBoard(onBoard);
  setLeftRef(4,0);
  setCurrState(0);
  setNumStates(2);
  updateStates(); // create the vector of states
  setHeaviness(); // set the heaviness of the block
  if (onBoard) { set(type, blockid); }
}

void Z::updateStates() {
  // create the vector of 4 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row - 1, leftRef.col + 1});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 1});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 2});
  states[0] = vec1;

  // State 1 (CW once from State 0)
  vector<Coordinate> vec2;
  vec2.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 1, leftRef.col + 1});
  vec2.emplace_back(Coordinate{leftRef.row - 2, leftRef.col + 1});
  states[1] = vec2;
}
