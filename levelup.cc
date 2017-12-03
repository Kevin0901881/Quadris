#include <memory>
#include "levelup.h"

LevelUp::LevelUp(Board* b) : board{b} {}

void LevelUp::execute() {
  board->levelUp(); // executes the levelup command of the board
}
