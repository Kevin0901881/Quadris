#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "graphicdisplay.h"
#include "cell.h"
#include "textdisplay.h"

class Grid {
  bool GameOver;
  std::vector<std::vector<Cell>> theGrid; //actual Grid

public:
  Grid(); //constructor

  Cell* getCell(int r, int c); // return a pointer to a specific cell
  std::vector<std::vector<Cell>> getCells(); // return theGrid
  void clearRow(int r); //clears row at r
  void setGameOver(bool over); //set GameOver
  bool getGameOver(); //reutnr GameOver
  bool isRowFull(int r); //checks if a row is full. r is the row number you wanna check

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
