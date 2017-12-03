#include <memory>
#include "leveldown.h"

LevelDown::LevelDown(Board* b) : board{b} {}

void LevelDown::execute() {
  board->levelDown(); // executes the leveldown command of the board
}
