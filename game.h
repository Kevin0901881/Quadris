#ifndef GAME_H
#define GAME_H
#include <string>
#include <memory>
#include "board.h"
#include "commandinterpreter.h"
#include "graphicdisplay.h"
#include "textdisplay.h"

class Game() {
  bool textOnly;
  unsigned int seed;
  std::string scriptfile;
  int n;
  std::unique_ptr<Board> board;
  std::unique_ptr<CommandInterpreter> commandInterpreter;
  std::unique_ptr<GraphicDisplay> graphicDisplay;
  std::unique_ptr<TextDisplay> textDisplay;
public:
  Game(bool textOnly, unsigned int seed, std::string scriptfile, int n, bool isSeedAvailable); // the constructor for the Game class
  void init(); // initializes the board, command interpreter, graphic display, and text display
  std::unique_ptr<Board> getBoard(); // gets a smart pointer to the Board
  std::unique_ptr<GraphicDisplay> getGraphicDisplay(); // gets a smart pointer to the GraphicDisplay
  std::unique_ptr<TextDisplay> getTextDisplay(); // gets a smart pointer to the TextDisplay
  // TODO: overload output operator
};

#endif
