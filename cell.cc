#include <string>
#include "cell.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

using namespace std;

//constructor
Cell::Cell(int x, int y) : x{x}, y{y} {
  type = "None";
}

// retrieve the type of block cell belongs to
string Cell::getType() {
  return type;
}

// retrieve the coordinate (x,y)
Coordinate Cell::getCoordinate() {
  Coordinate cd = {x, y};
  return cd;
}

void Cell::set(string s) {
  type = s;
}

void Cell::unset() {
  type = "None";
}

bool Cell::isOccupied() {
  if (type == "None") {
    return false;
  } else {
    return true;
  }
}

// notify textdisplay and graphicsdisplay
void Cell::draw() {
  td->drawCell();
  gd->drawCell();
}
