#include <memory>
#include "right.h"

Right::Right(Board* b) : board{b} {}

void Right::execute() {
  board->moveRight(false); // executes the right command of the board
}
