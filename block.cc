#include <string>
#include <memory>
#include "block.h"
#include "cell.h"

using namespace std;
Block::~Block() {}

int Block::getLevel() {
  return level;
}

vector<Cell*> Block::getCells() {
  return cells;
}

bool Block::isEmpty() {
  if (cells.empty()) return true;
  return false;
}

bool Block::isValidMove(string dir) {
  if (dir == "left") {
    // check if the pointer to the left is isOccupied

  } else if (dir == "right") {

  } else if (dir == "down") {

  } else if (dir == "cw") {

  } else if (dir == "ccw") {

  } else {
    return false;
  }
}

void Block::moveLeft() {
  if (isValidMove("left")) {
    unset();
    // move to the left
    draw();
  }
}

void Block::moveRight() {
  if (isValidMove("right")) {
    unset();
    // move to the right;
    draw();
  }
}

void Block::moveDown() {
  if (isValidMove("down")) {
    unset();
    // move to the down;
    draw();
  }
}

void Block::drop() {
  // drop it
  draw();
}

void Block::draw() {
  for (int i = 0; i < 4; ++i) {
    cells[i]->draw();
  }
}

void Block::unset() {
  for (int i = 0; i < 4; ++i) {
    cells[i]->unset();
  }
}

void Block::updateCounter() {
  counter++;
}
