#include <string>
#include "cell.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

using namespace std;

//constructor
Cell::Cell(int r, int c) :
row{r}, col{c}, id{-1}, blockType{"None"}, hint{false} {}

// retrieve the type of block cell belongs to
string Cell::getBlockType() {
  return blockType;
}

// retrieve the coordinate (x,y)
Coordinate Cell::getCoord() {
  Coordinate cd = {row, col};
  return cd;
}

void Cell::set(string b, int blockid) {
  blockType = b;
  id = blockid;
}

void Cell::unset() {
  blockType = "None";
  id = -1;
}

// set cell to either be on board or not (for next blocks)
void Cell::setOnBoard(bool ob) {
  onBoard = ob;
}

// retrieve whether cell is on board or not
bool Cell::getOnBoard() const {
  return onBoard;
}

bool Cell::isOccupied() {
  if (blockType == "None") {
    return false;
  } else {
    return true;
  }
}

void Cell::moveDown() {
  row+=1;
}

void Cell::setID(int blockid) {
  id = blockid;
}

int Cell::getID() {
  return id;
}

ostream& operator<<(ostream &out, const Cell &c) {
  if (c.blockType == "None") {
    out << " ";
  } else {
    out << c.blockType;
  }
  return out;
}
