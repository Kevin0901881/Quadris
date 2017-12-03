#include "down.h"
#include <memory>

Down::Down(Board* b) : board{b} {}

void Down::execute() {
  board->down(); // executes the down command of the board
}
