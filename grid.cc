#include <vector>
#include <iostream>
#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

using namespace std;

Grid::Grid() : GameOver{false} {

  //set up empty grid
  for (int i = 0; i < 18; ++i) {
    vector<Cell> row;
    for (int j = 0; j < 11; ++j) {
      Cell c{i, j};
      row.emplace_back(c);
    }
    theGrid.emplace_back(row);
  }
}

Cell* Grid::getCell(int r, int c) {
  return &theGrid[r][c];
}

vector<vector<Cell>> Grid::getCells() {
  return theGrid;
}


void Grid::clearRow(int r) {
  theGrid.erase(theGrid.begin() + r); //erase the vector at r and all elements

  //call movedown method in cells on the vector<vector <Cells>> above r
  for (int i = r - 1; i >= 0; --i) {
    for (int j = 0; j < 11; ++j) {
      theGrid[i][j].moveDown();
    }
  }
  //insert in very top row
  vector<Cell> topRow;
  for (int i = 0; i < 11; ++i) {
    Cell c{0, i};
    topRow.emplace_back(c);
  }
  theGrid.insert(theGrid.begin(), topRow); //insert it at the beginning of vector
}

void Grid::setGameOver(bool over) {GameOver = over;}

bool Grid::getGameOver() {return GameOver;}

bool Grid::isRowFull(int r) {
  for (int i = 0; i < 11; ++i) {
    if (theGrid[r][i].getBlockType() == "None") {
      return false;
    }
  }
  return true;
}

ostream &operator<<(std::ostream &out, const Grid &g) {
  for (int i = 0; i < 18; ++i) {
    for (int j = 0; j < 11; ++j) {
      if (g.theGrid[i][j].getOnBoard() == true) {
        out << g.theGrid[i][j];
      } else {
        out << " ";
      }
    }
    out << endl;
  }
  return out;
}
