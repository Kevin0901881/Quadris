#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <cstring>
#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
  bool textOnly = false;
  unsigned int seed = 0;
  bool isSeedAvailable = false;
  string scriptfile = "sequence.txt";
  int n = 0;

  // iterates through the arguments passed into the command line
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-text") == 0) { // enable text-only mode
      textOnly = true;
    } else if (strcmp(argv[i], "-seed") == 0) { // sets a custom seed for the random number generator
      if (typeid(seed) == typeid(argv[i + 1])) { // checks if the seed is valid
        seed = *argv[++i];
        isSeedAvailable = true;
      } else {
        cerr << "invalid seed entry" << endl;
        return 0;
      }
    } else if (strcmp(argv[i], "-scriptfile") == 0) { // sets a custom scriptfile
      if (typeid(scriptfile) == typeid(argv[i + 1])) { // checks if the scriptfile is valid
        scriptfile = argv[++i];
      } else {
        cerr << "invalid scriptfile entry" << endl;
        return 0;
      }
    } else if (strcmp(argv[i], "-startlevel") == 0) { // sets the level
      if (typeid(n) == typeid(*argv[i + 1] - '0') && (*argv[i + 1] - '0') <= 4) { // checks if the level is valid
        n = *argv[++i] - '0';
      } else {
        cerr << "invalid level entry" << endl;
        return 0;
      }
    }
  }

  // starts the game based on command line specifications
  if (isSeedAvailable) {
    Game game(textOnly, seed, scriptfile, n, true);
  } else {
    Game game(textOnly, seed, scriptfile, n, false);
  }

  return 0;
}
