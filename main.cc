#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <typeinfo>

using namespace std;

int main(int argc, char* argv[]) {
  bool textOnly = false;
  unsigned int seed = 0;
  string scriptfile = "sequence.txt";
  int n = 0;

  // iterates through the arguments passed into the command line
  for (int i = 0; i < argc; i++) {
    if (argv[i] == "-text") { // enable text-only mode
      textOnly = true;
    } else if (argv[i] == "-seed") { // sets a custom seed for the random number generator
      if (typeid(seed) == typeid(argv[i + 1])) { // checks if the seed is valid
        seed = argv[++i];
      } else {
        cerr << "invalid seed entry" << endl;
        return 0;
      }
    } else if (argv[i] == "-scriptfile") { // sets a custom scriptfile
      if (typeid(scriptfile) == typeid(argv[i + 1])) { // checks if the scriptfile is valid
        scriptfile = argv[++i];
      } else {
        cerr << "invalid scriptfile entry" << endl;
        return 0;
      }
    } else if (argv[i] == "-startlevel") { // sets the level
      if (typeid(n) == typeid(argv[i + 1] && argv[i + 1] <= 4)) { // checks if the level is valid
        n = argv[++i];
      } else {
        cerr << "invalid level entry" << endl;
        return 0;
      }
    }
  }

  // starts the game based on command line specifications
  Game game(textOnly, seed, scriptfile, n);
  
  return 0;
}
