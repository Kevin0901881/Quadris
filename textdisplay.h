#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "board.h"

// class Board;
class TextDisplay {
  Board *b;
public:
 TextDisplay(Board *b); // constructor
 void drawBoard(); // draws the board
 void gameOver();

};


#endif
