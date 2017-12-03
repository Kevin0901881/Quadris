#include <string>
#include <memory>
#include "game.h"

using namespace std;

// Creates the board, command interpreter, graphic display, and text display, and initiates the command interpreter
// TODO: do the quit

Game::Game(bool textOnly, unsigned int seed, string scriptfile, int n, bool isSeedAvailable) :
  textOnly{textOnly}, seed{seed}, scriptfile{scriptfile}, n{n}, isSeedAvailable{isSeedAvailable} {
    init(); // creates pointers to the objects and runs the command interpreter
}

void Game::init() {
  if (isSeedAvailable) {
    board = make_unique<Board>(seed, scriptfile, n); // TODO: parameters subject to change
  } else {
    board = make_unique<Board>(scriptfile, n); // TODO: parameters subject to change
  }
  commandInterpreter = make_unique<CommandInterpreter>(board.get(), scriptfile);
  if (!textOnly) {
    graphicDisplay = make_unique<GraphicDisplay>(board.get()); // TODO: parameters subject to change
  }
  textDisplay = make_unique<TextDisplay>(board.get()); // TODO: parameters subject to change

  while(true) {
    commandInterpreter->readInput();
    try { // a try-catch block is used in case there is an invalid input
      commandInterpreter->parseInput();
      commandInterpreter->execute();
    } catch (string s) {
      cerr << s << endl;
    }
    textDisplay->drawBoard(); // TODO: paramaters subject to change
    if (board->gameOver()) {
      textDisplay->gameOver();
      return;
    }
  }
}

unique_ptr<Board> Game::getBoard() {
  return board;
}

unique_ptr<GraphicDisplay> Game::getGraphicDisplay() {
  return graphicDisplay;
}

unique_ptr<TextDisplay> Game::getTextDisplay() {
  return textDisplay;
}

ostream& operator<<(ostream& out, const Game& game) {
  out << *(game.textDisplay);
  return out;
}
