#include <string>
#include "cell.h"
// #include "grid.h"
#include "board.h"
#include "graphicdisplay.h"

using namespace std;

GraphicDisplay::GraphicDisplay(Board *b) : b{b}, xw{gridWidth, gridHeight} {
  xw.fillRectangle(0, 0, gridWidth, gridHeight, 1);
}

void GraphicDisplay::displayG() {
  string temp;

  xw.drawString(13*cellSize, 1*cellSize, "Q U A D R I S", 9);

  xw.drawString(12*cellSize, 3*cellSize, "Level:", 9);
  temp = to_string(b->getLevel());
  xw.drawString(15*cellSize, 3*cellSize, temp, 9);

  xw.drawString(12*cellSize, 4*cellSize, "Score:", 9);
  temp = to_string(b->getCurrentScore());
  xw.drawString(15*cellSize, 4*cellSize, temp, 9);

  xw.drawString(12*cellSize, 5*cellSize, "HiScore:", 9);
  temp = to_string(b->getHiScore());
  xw.drawString(15*cellSize, 5*cellSize, temp, 9);


  for (int i = 0; i < 18; ++i) {
    for (int j = 0; j < 11; ++j) {
      string bType = b->getGrid()->getCells()[i][j].getBlockType();
      if (bType == "J") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 2);
      } else if (bType == "O") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 3);
      } else if (bType == "S") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 4);
      } else if (bType == "Z") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 5);
      } else if (bType == "I") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 6);
      } else if (bType == "L") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 7);
      } else if (bType == "T") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 9);
      } else if (bType == "?") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 1);
      } else if (bType == "*") {
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 8);
      } else { //None
        xw.fillRectangle(j*cellSize, i*cellSize, cellSize, cellSize, 0);
      }
    }
  }

  //clear next blocks

  xw.drawString(12*cellSize, 7*cellSize, "Next:", 9);

  for (int x = 13; x < 17; ++x) {
    for (int y = 9; y < 11; ++y) {
      xw.fillRectangle(x*cellSize, y*cellSize, cellSize, cellSize, 1);
    }
  }

  if (b->getNextBlock() == "J") {
    xw.fillRectangle(13*cellSize, 9*cellSize, cellSize, cellSize, 2);
    for (int c = 13; c < 16; ++c) {
    xw.fillRectangle(c*cellSize, 10*cellSize, cellSize, cellSize, 2);
    }
  } else if (b->getNextBlock() == "I") {
    for (int c = 13; c < 17; ++c) {
    xw.fillRectangle(c*cellSize, 9*cellSize, cellSize, cellSize, 6);
    }
  } else if (b->getNextBlock() == "O") {
    xw.fillRectangle(13*cellSize, 9*cellSize, cellSize, cellSize, 3);
    xw.fillRectangle(14*cellSize, 9*cellSize, cellSize, cellSize, 3);
    xw.fillRectangle(13*cellSize, 10*cellSize, cellSize, cellSize, 3);
    xw.fillRectangle(14*cellSize, 10*cellSize, cellSize, cellSize, 3);
  } else if (b->getNextBlock() == "S") {
    xw.fillRectangle(13*cellSize, 10*cellSize, cellSize, cellSize, 4);
    xw.fillRectangle(14*cellSize, 9*cellSize, cellSize, cellSize, 4);
    xw.fillRectangle(14*cellSize, 10*cellSize, cellSize, cellSize, 4);
    xw.fillRectangle(15*cellSize, 9*cellSize, cellSize, cellSize, 4);
  } else if (b->getNextBlock() == "T") {
    for (int c = 13; c < 16; ++c) {
      xw.fillRectangle(c*cellSize, 9*cellSize, cellSize, cellSize, 9);
    }
    xw.fillRectangle(14*cellSize, 10*cellSize, cellSize, cellSize, 9);
  } else if (b->getNextBlock() == "L") {
    xw.fillRectangle(15*cellSize, 9*cellSize, cellSize, cellSize, 7);
    for (int c = 13; c < 16; ++c) {
    xw.fillRectangle(c*cellSize, 10*cellSize, cellSize, cellSize, 7);
    }
  } else if (b->getNextBlock() == "Z") {
    xw.fillRectangle(13*cellSize, 9*cellSize, cellSize, cellSize, 5);
    xw.fillRectangle(14*cellSize, 9*cellSize, cellSize, cellSize, 5);
    xw.fillRectangle(14*cellSize, 10*cellSize, cellSize, cellSize, 5);
    xw.fillRectangle(15*cellSize, 10*cellSize, cellSize, cellSize, 5);
  }
}
