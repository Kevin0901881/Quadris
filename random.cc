#include <memory>
#include "random.h"
#include "board.h"

Random::Random(Board* b) : board{b} {}

void Random::execute() {
  board->random(); // executes the random command of the board;
}
