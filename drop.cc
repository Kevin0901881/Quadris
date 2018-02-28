#include <memory>
#include "drop.h"

Drop::Drop(Board* b) : board{b} {}

void Drop::execute() {
  board->drop(false); // executes the drop command of the board
}
