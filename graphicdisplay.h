#ifndef GRAPHICDISPLAY_H__
#define GRAPHICDISPLAY_H__
#include <string>
#include "window.h"
#include "block.h"
#include "score.h"

class Board;

class GraphicDisplay {
  const int cellSize = 40; //each cell dimension
  const int gridHeight = 720; //height of entire window
  const int gridWidth = 720; //width of entire window
  Board *b;
  Xwindow xw;

public:
  GraphicDisplay(Board *b); //constructor

  void displayG();
};


#endif
