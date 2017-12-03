#include <memory>
#include "hint.h"

Hint::Hint(Board* b) : board{b} {}

void Hint::execute() {
  board->hint(); // executes the hint command of the board
}
