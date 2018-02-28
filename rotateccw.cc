#include <memory>
#include "rotateccw.h"

RotateCCW::RotateCCW(Board* b) : board{b} {}

void RotateCCW::execute() {
  board->rotateCCW(); // executes the rotateccw command of the board
}
