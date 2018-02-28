#include <memory>
#include "rotatecw.h"

RotateCW::RotateCW(Board* b) : board{b} {}

void RotateCW::execute() {
  board->rotateCW(false); // calls the rotatecw command of the board
}
