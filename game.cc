#include <string>
#include <memory>
#include "game.h"

using namespace std;

// Creates the board, command interpreter, graphic display, and text display, and initiates the command interpreter

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
    graphicDisplay->displayG();
  }
  textDisplay = make_unique<TextDisplay>(board.get()); // TODO: parameters subject to change
  textDisplay->drawBoard();

  while(true) {
    commandInterpreter->readInput();
    try { // a try-catch block is used in case there is an invalid input
      commandInterpreter->parseInput();
      commandInterpreter->execute();
    } catch (exception e) {
      cerr << "Invalid input" << endl;
    } catch (string s) {
      cerr << "Invalid input" << endl;
    }
    if (!textOnly) {
      graphicDisplay->displayG();
    }
    textDisplay->drawBoard();
    if (board->gameOver()) {
      textDisplay->gameOver();
      return;
    }
  }
}
