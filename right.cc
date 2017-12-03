#include <memory>
#include "right.h"

Right::Right(Board* b) : board{b} {}

void Right::execute() {
  board->right(); // executes the right command of the board
}
