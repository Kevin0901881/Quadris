#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include <string>
#include "cell.h"
#include "graphicsdisplay.h"
#include "block.h"

class Board {
  vector<vector<Cell*>> theGrid;

public:
  void init();
  void setCell();
  Cell* getCell(int x, int y);
  bool gameOver();
  void setGD();
  void setTD();
  bool fullRow();
  void clear();
  void moveLeft(Block *b);
  void moveRight(Block *b);
  void moveDown(Block *b);
  void rotateCW(Block *b);
  void rotateCCW(Block *b);
  void drop();
  void levelUp();
  void levelDown();
  void randomizer();
  void restart();
  void replaceBlock(string s);
  void hint();
};


#endif
