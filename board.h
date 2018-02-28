#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <map>
#include "cell.h"
#include "block.h"
#include "level.h"
#include "score.h"
#include "grid.h"

class Board {
  std::unique_ptr<Grid> g; // pointer to the Grid
  std::unique_ptr<Score> s; // pointer to the Score
  std::unique_ptr<Level> l; // pointer to the Level
  unsigned int seed;
  int level;
  std::map<int, std::unique_ptr<Block>> bmap; // pair that keeps track of all the blocks created
  std::unique_ptr<Block> nextBlock; // points to the next block
  int numBlocks = 0; //block id so it increments
  int numOnScreen = 0; //number of blocks on the grid
  int lvlfourBlocks; // keeps track of the number of blocks dropped in level 4
  int lvlfourRows; // keeps track of # of rows cleared in level 4
  bool isSeedAvailable;
  bool isHintActivated = false;
  std::vector<Cell*> hintcells;
  std::string scriptfile;
public:
  // creation of board
  Board(std::string scriptfile, int level);
  Board(unsigned int seed, std::string scriptfile, int level);
  void init();

  // getters
  int getLevel();
  Grid* getGrid();
  std::string getNextBlock();

  // for gameover purposes
  bool checkStartPos();
  bool gameOver();
  void restart();

  // for scoring purposes
  int rowClearScore(int rowsCleared, bool isHint);
  int blockClearScore(Block* b, bool isHint);
  int getHiScore();
  int getCurrentScore();

  // moves
  void moveLeft();
  bool moveRight(bool isHint);
  void moveDown();
  void rotateCW(bool isHint);
  void rotateCCW();
  int drop(bool isHint);
  void replaceBlock(std::string s);
  void hint();
  void unsetHint(std::vector<Cell*>);
  void norandom(std::string filename);
  void random();

  // change level
  void levelUp();
  void levelDown();
};

#endif
