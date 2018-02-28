#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Board *b) : b{b} {} //constructor

void TextDisplay::drawBoard() {
  cout << "Q U A D R I S" << endl << endl;

  cout << "Level:" << "   " << b->getLevel() << endl; //current level
  cout << "Score:" << "   " << b->getCurrentScore() << endl; //current game's score
  cout << "HiScore:" << " " << b->getHiScore() << endl; //HiScore

  for (int i = 0; i < 11; ++i) { //top border
    cout << '-';
  }
  cout << endl;
  cout << *(b->getGrid());

  for (int i = 0; i < 11; ++i) { //bottom border
    cout << '-';
  }
  cout << endl;

  cout << "Next:" << endl;
  if (b->getNextBlock() == "J") { //prints out next block
    cout << "J" << endl;
    cout << "JJJ" << endl;
  } else if (b->getNextBlock() == "O") {
    cout << "OO" << endl;
    cout << "OO" << endl;
  } else if (b->getNextBlock() == "T") {
    cout << "TTT" << endl;
    cout << " T " << endl;
  } else if (b->getNextBlock() == "L") {
    cout << "  L" << endl;
    cout << "LLL" << endl;
  } else if (b->getNextBlock() == "I") {
    cout << "IIII" << endl;
  } else if (b->getNextBlock() == "S") {
    cout << " SS" << endl;
    cout << "SS" << endl;
  } else if (b->getNextBlock() == "Z") {
    cout << "ZZ" << endl;
    cout << " ZZ" << endl;
  }
}


void TextDisplay::gameOver(){
  cout<< "Game Over" << endl;
}
