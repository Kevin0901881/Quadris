// #include <memory>
// #include <cstdlib>
// #include <memory>
// #include "level.h"
//
// using namespace std;

// Level::Level(int n) : n{n} {
//   isSeedAvailable = false;
// }
//
// Level::Level(int n, unsigned int seed) : n{n}, seed{seed} {
//   isSeedAvailable = true;
// }
//
// void Level::setLevel(int n) {
//   if (n > 4) { // if command multiplier is used and level goes above 4
//     n = 4;
//   } else if (n < 0) { // if command multiplier is used and level goes below 0
//     n = 0;
//   }
//   this->n = n;
// }
//
// int Level::getLevel() {
//   return n;
// }
