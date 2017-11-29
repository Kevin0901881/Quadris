#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
#include <memory>
#include "coordinate.h"

class Cell {
  int x;
  int y;
  std::unique_ptr<GraphicDisplay> gd;
  std::unique_ptr<TextDisplay> td;
  std::string type;
public:
  Cell();
  std::string getType();
  Coordinate getCoordinate();
  void set();
  void unset();
  bool isOccupied();
  void draw();
};

#endif
