#include <memory>
#include "restart.h"

Restart::Restart(Board* b) : board{b} {}

void Restart::execute() {
  board->restart(); // executes the restart command of the board
}
