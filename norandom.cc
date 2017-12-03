#include <string>
#include <memory>
#include "norandom.h"

NoRandom::NoRandom(Board* b, string scriptfile) : board{b}, scriptfile{scriptfile} {}

void NoRandom::execute() {
  board->setScriptfile(scriptfile); // executes the norandom command of the board
}
