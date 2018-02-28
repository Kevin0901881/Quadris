#include <string>
#include <vector>
#include <memory>
#include "block.h"
#include "cell.h"
#include "grid.h"

using namespace std;

Block::~Block() {}
// remove cell from the block that will be cleared with a row
void Block::removeCell(Coordinate c) {
  Coordinate bcoord;
  for (unsigned int i = 0; i < cells.size(); ++i) {
    bcoord = cells[i]->getCoord();
    if ((bcoord.row == c.row) && (bcoord.col == c.col)) {
      cells.erase(cells.begin()+i);
      break;
    }
  }
}

void Block::setWidth(int w) {
  width = w;
}

void Block::setHeight(int h) {
  height = h;
}

void Block::setLevel(int lvl) {
  level = lvl;
}

void Block::setBlockCells(vector<Cell*> newcells) {
  cells = newcells;
}

// set the heaviness of blocks
void Block::setHeaviness() {
  if ((level == 3) || (level == 4)) {
    heavy = 1;
  } else {
    heavy = 0;
  }
}

vector<Cell*> Block::getBlockCells() {
  return cells;
}

int Block::getHeaviness() {
  return heavy;
}

// returns the level the block was created in
int Block::getLevel() {
  return level;
}

int Block::getHeight() {
  return height;
}

void Block::setLeftRef(int r, int c) {
  leftRef.row = r;
  leftRef.col = c;
}

Coordinate Block::getLeftRef() {
  return leftRef;
}

std::map<int, std::vector<Coordinate>> Block::getStates() {
  return states;
}

void Block::setCurrState(int x) {
  currState = x;
}

void Block::setNumStates(int x) {
  numStates = x;
}

int Block::getCurrState() {
  return currState;
}

int Block::getNumStates() {
  return numStates;
}

// checks if the block's cells are all cleared
bool Block::isEmpty() {
  if (cells.empty()) return true;
  return false;
}

//create a vector with all the coordinates of the current cells of the block
vector<Coordinate> Block::createCoords() {
  vector<Coordinate> coords;

  for (unsigned int i = 0; i < cells.size(); ++i) {
    Coordinate c = cells[i]->getCoord();
    coords.emplace_back(c);
  }
  return coords;
}

// check whether a cell is inside the block
bool Block::inBlock(int x, int y) {
  vector<Coordinate> coords = createCoords(); // hold the coordinates of curr cells

  for (unsigned int i = 0; i < cells.size(); ++i) {
    if ((coords[i].row == x) && (coords[i].col == y)) {
      return true;
    }
  }
  return false;
}

// check if the cell the block is trying to shift into is occupied or not
// (only checks for left, right, down shift)
bool Block::isValidShift(string dir) {
  vector<Coordinate> coords = createCoords(); // hold the coordinates of curr cells
  vector<vector<Cell>> gridcells = g->getCells(); // hold the cells of the grid

  for (unsigned int i = 0; i < cells.size(); ++i) {
    // find coordinates of the new potential cell of the block
    int x = coords[i].row;
    int y = coords[i].col;
    if (dir == "left") {
      y -= 1;
    } else if (dir == "right") {
      y += 1;
    } else if (dir == "down") {
      x += 1;
    }

    if ((y < 0) || (y > 10) || (x > 17)) { // check if cell is not on board
      return false;
    } else if (gridcells[x][y].isOccupied()) { // check if cell is occupied
      // check if occupied cell is part of the same block
      if (!inBlock(x,y)) {
        return false;;
      }
    }
  }
  return true;
}

// shift the block (returns true/false for drop)
bool Block::shift(string dir, bool isDrop, bool isHint) {
  vector<Coordinate> coords = createCoords(); // hold the coordinates of curr cells
  bool shifted = false;
  int x,y;
  if (isValidShift(dir)) {
    if (!isHint) {unset();}
    for (unsigned int i = 0; i < cells.size(); ++i) {
      if (dir == "left") {
        x = coords[i].row;
        y = coords[i].col - 1;
      } else if (dir == "right") {
        x = coords[i].row;
        y = coords[i].col + 1;
      } else {
        x = coords[i].row + 1;
        y = coords[i].col;
      }
      cells[i] = g->getCell(x,y);
    }
    // update bottom left reference point
    // left shift - move the coords of the left reference one to the left
    if (dir == "left") setLeftRef(leftRef.row, leftRef.col - 1);
    // right shift - move the coords of the left reference one to the right
    if (dir == "right") setLeftRef(leftRef.row, leftRef.col + 1);
    // down shift - move the coords of the left reference down by one
    if (dir == "down") setLeftRef(leftRef.row + 1, leftRef.col);

    if (!isDrop && !isHint) {
      set(type, ID); // set the new cells
    }
    updateStates();
    shifted = true;
  } else {
    shifted = false;
  }
  return shifted;
}

// check if it's possible to rotate
bool Block::isValidRotate(string dir) {
  int x, y, newState;
  vector<vector<Cell>> gridcells = g->getCells();

  if (dir == "cw") { // rotate clockwise

    // decide which state to go to
    if (currState == numStates - 1) { // go back to first state
      newState = 0;
    } else { // go forward with states 0->1, 1->2, etc.
      newState = currState + 1;
    }
  } else { // rotate counter clockwise

    // decide which state to go to
    if (currState == 0) { // go to final state
      newState = numStates - 1;
    } else { // go backward with states 1->0, 2->1, etc.
      newState = currState - 1;
    }
  }


  // check if each cell in the next rotation is valid for rot to happen
  for (unsigned int i = 0; i < cells.size(); ++i) {
    x = states[newState][i].row;
    y = states[newState][i].col;
    if ((y < 0) || (y > 10) || (x > 17)) { // check if cell is not on board
      return false;
    } else if (gridcells[x][y].isOccupied()) { // check if cell is occupied
      if (!inBlock(x, y)) { // see if the cell is part of this block
        return false;
      }
    }
  }
  return true;
}

void Block::rotate(string dir, bool isHint) {
  int x,y;
  if (isValidRotate(dir)) {
    if (!isHint) { unset(); } // unset current blocks

    // decide the state to rotate to
    if (dir == "cw") { // rotate clockwise
      if (currState == numStates - 1) {
        currState = 0;
      } else {
        currState += 1;
      }
    } else { // rotate counter clockwise
      if (currState == 0) {
        currState = numStates - 1;
      } else {
        currState -= 1;
      }
    }

    // new coordinates for block
    vector<Coordinate> newCoords = states[currState];

    // update the new cells of the block
    for (unsigned int i = 0; i < cells.size(); ++i) {
      x = newCoords[i].row;
      y = newCoords[i].col;
      cells[i] = g->getCell(x,y);
    }
    // switch the width and height of the block
    int temp = width;
    width = height;
    height = temp;

    if (!isHint) { set(type, ID); } // set the new blocks
  }
}

// move the block as far down as it can go without overtaking another cell
void Block::drop(bool isHint) {
  // continue shifting down until it's not possible
  while (shift("down", true, isHint));
  if (!isHint) {
    set(type, ID);
  }
}

// set the cells of block
void Block::set(string type, int blockid) {
  for (unsigned int i = 0; i < cells.size(); ++i) {
    if (cells[i]->getOnBoard()) {
      cells[i]->set(type, blockid);
    }
  }
}

// unset the current cells of the block
void Block::unset() {
  for (unsigned int i = 0; i < cells.size(); ++i) {
    cells[i]->unset();
  }
}

void Block::setOnBoard(bool onBoard) {
  for (unsigned int i = 0; i < cells.size(); ++i) {
    if (cells[i]->getOnBoard()) {
      // don't change the cell
    } else {
      cells[i]->setOnBoard(onBoard);
    }
  }
}

void Block::setID(int blockid) {
  ID = blockid;
  for (unsigned int i = 0; i < cells.size(); ++i) {
    cells[i]->setID(blockid);
  }
}

void Block::updateCounter() {
  counter++;
}

void Block::addCell(Coordinate c) {
  cells.emplace_back(g->getCell(c.row, c.col));
}

void Block::setType(string btype) {
  type = btype;
}

string Block::getType() {
  return type;
}
