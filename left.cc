#include "left.h"

Left::Left(Board* b) : board{b} {}

void Left::execute() {
  board->left(); // executes the left command of the board
}
