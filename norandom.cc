#include <string>
#include <memory>
#include "norandom.h"
#include "board.h"

using namespace std;

NoRandom::NoRandom(Board* b, string scriptfile) : board{b}, scriptfile{scriptfile} {}

void NoRandom::execute() {
  board->norandom(scriptfile); // executes the norandom command of the board
}
