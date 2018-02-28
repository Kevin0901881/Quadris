#include <vector>
#include <memory>
#include <map>
#include <string>
#include "board.h"
#include "l0.h"
#include "l1.h"
#include "l2.h"
#include "l3.h"

using namespace std;

// FOR CREATION OF BOARD
// construct when no seed
Board::Board(string scriptfile, int level) :
g{make_unique<Grid>()}, s{make_unique<Score>()},
level{level}, scriptfile{scriptfile} {
  isSeedAvailable = false;
  init(); // create the board's level and blocks
}

// constructor for when there's a seed
Board::Board(unsigned int seed, string scriptfile, int level) :
g{make_unique<Grid>()}, s{make_unique<Score>()},
seed{seed}, level{level}, scriptfile{scriptfile} {
  isSeedAvailable = true;
  init(); // create the board's level and blocks
}

// create the level and create the current and next blocks
void Board::init() {
  if (level == 0) { // create level 0
    l = make_unique<L0>();
  } else if (level == 1) { // create level 1
    if (isSeedAvailable) {
      l = make_unique<L1>(seed);
    } else {
      l = make_unique<L1>();
    }
  } else if (level == 2) { // create level 2
    if (isSeedAvailable) {
      l = make_unique<L2>(seed);
    } else {
      l = make_unique<L2>();
    }
  } else if (level == 3) { // create level 3
    if (isSeedAvailable) {
      l = make_unique<L3>(seed, false);
    } else {
      l = make_unique<L3>(false);
    }
  } else { // create level 4
    lvlfourBlocks = 0;
    if (isSeedAvailable) {
      l = make_unique<L3>(seed, true);
    } else {
      l = make_unique<L3>(true);
    }
  }
  bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true)); // add the current block into the map of numBlocks
  nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false)); // make the next block
}

// GETTERS
// retrieve the current level
int Board::getLevel() {
  return level;
}

// retrieve the Grid*
Grid* Board::getGrid() {
  return g.get();
}

// retrieve the type of the next block
string Board::getNextBlock() {
  return nextBlock->getType();
}

// FOR GAME OVER PURPOSES
// check if it's possible to place a new piece at the starting pos
bool Board::checkStartPos() {
  bool canStart = true;
  vector<vector<Cell>> gridcells = g->getCells();

  // check row 3
  for (int i = 0; i < 4; ++i) {
    if (gridcells[3][i].isOccupied()) {
      canStart = false;
      break;
    }
  }
  if (canStart) {
    // check row 4
    for (int i = 0; i < 3; ++i) {
      if (gridcells[4][i].isOccupied()) {
        canStart = false;
        break;
      }
    }
  }
  return canStart;
}

// check if the game is over
bool Board::gameOver() {
  // two cases: place the block down it'll go into the rotate area
  // the area for the starting block is filled
  vector<vector<Cell>> gridcells = g->getCells();
  if (g->getGameOver()) {
    return true;
  } else {
    return false;
  }
}

// clear the board and reset the current score
void Board::restart() {
  if (isHintActivated) { unsetHint(hintcells);}
  s->restart();

  // go through all the blocks created and unset all cells
  for (int i = 0; i <= numBlocks; ++i) {
    bmap[i]->unset();
  }
  nextBlock->unset();
  bmap.clear();
  numBlocks = 0;
  lvlfourBlocks = 0;
  bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true)); // add the current block into the map of numBlocks
  nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false)); // make the next block
}

// FOR SCORING PURPOSES
// update the score based on how many rows were cleared
int Board::rowClearScore(int rowsCleared, bool isHint) {
  int score = 0;
  score = s->rowClear(rowsCleared, level, isHint);
  return score;
}

// update the score based on the block that was cleared
int Board::blockClearScore(Block* b, bool isHint) {
  int score = 0;
  score = s->blockClear(b, isHint);
  return score;
}

// retrieve the high score
int Board::getHiScore() {
  return s->getHiScore();
}

// retrieve the current score
int Board::getCurrentScore() {
  return s->getCurrentScore();
}

// MOVES
// shift block to the left (if possible)
void Board::moveLeft() {
  if (isHintActivated) { unsetHint(hintcells); }
  bmap[numBlocks]->shift("left", false, false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift("down", false, false);
  }
}

// shift block to the right (if possible)
bool Board::moveRight(bool isHint) {
  if (isHintActivated) { unsetHint(hintcells); }
  bool shiftright = bmap[numBlocks]->shift("right", false, isHint);
  if (!isHint) {
    if (bmap[numBlocks]->getHeaviness() == 1) {
      bmap[numBlocks]->shift("down", false, isHint);
    }
  }
  return shiftright;
}

// shift block down (if possible)
void Board::moveDown() {
  if (isHintActivated) { unsetHint(hintcells); }
  bmap[numBlocks]->shift("down", false, false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift("down", false, false);
  }
}

// rotate block clockwise (if possible)
void Board::rotateCW(bool isHint) {
  if (isHintActivated) { unsetHint(hintcells); }
  bmap[numBlocks]->rotate("cw", isHint);
  if (!isHint){
    if (bmap[numBlocks]->getHeaviness() == 1) {
      bmap[numBlocks]->shift("down", false, isHint);
    }
  }
}

// rotate block counter clockwise (if possible)
void Board::rotateCCW() {
  if (isHintActivated) { unsetHint(hintcells); }
  bmap[numBlocks]->rotate("ccw", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift("down", false, false);
  }
}

// move block as far down as possible
int Board::drop(bool isHint) {
  if (isHintActivated) { unsetHint(hintcells);}
  bmap[numBlocks]->drop(isHint); // go as far as it can (doesn't set cells until check for any cleared rows)

  int numRows = bmap[numBlocks]->getHeight(); // number of potential full rows
  int botRow = bmap[numBlocks]->getLeftRef().row; // the bottom row of the block
  int blockID;
  int numCleared = 0;
  int increasedscore = 0;
  vector<vector<Cell>> gridcells = g->getCells();

  // use left reference point and height to determine which rows it got put in
  // then it deletes any full rows
  for (int i = 0; i < numRows; ++i) {
    if (g->isRowFull(botRow)) {
      // go through all cells in the row that's full
      // and detach them from the blocks
      for (int j = 0; j < 11; ++j) {
        blockID = g->getCell(botRow, j)->getID(); // get ID of the cell

        Coordinate c = gridcells[botRow][j].getCoord(); // get coordinates of the cell to be erased
        if (!isHint) {g->getCell(botRow, j)->unset();}

        bmap[blockID]->removeCell(c); //remove the cell from the block

        if (bmap[blockID]->isEmpty()) {
          increasedscore += blockClearScore(bmap[blockID].get(), isHint);
        }
        if (isHint) {bmap[blockID]->addCell(c);}
      }
      if (!isHint) {g->clearRow(botRow);} // deletes the row
      numCleared++; // increase the count of rows that are cleared
    }
  }
  if (numCleared > 0) {
    increasedscore += rowClearScore(numCleared, isHint); // run function to update Score
  }
  // check if any cells are over the top
  for (int i = 0; i < 11; ++i) {
    if (gridcells[2][i].isOccupied()) {
      g->setGameOver(true);
    } else {
      g->setGameOver(false);
    }
  }

  if (level == 4) {
    lvlfourBlocks++;
    lvlfourRows += numCleared; //update the #rows cleared in lvl 4
    if ((lvlfourBlocks % 5) == 0) { // if 5 or 10 or 15 ... blocks have been placed
      if (lvlfourRows == 0) {
        // if no rows have been cleared then create a CenterBlock and drop it
        numBlocks++; // increase the counter for total number of blocks created
        numOnScreen++;
        bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true, "*"));
        bmap[numBlocks]->drop(false);
        nextBlock->setID(numBlocks + 1);
      } else {
        lvlfourRows = 0;
      }
    }
  }

  if (!isHint) {
    if (checkStartPos()) {
      g->setGameOver(false);
      // add the old next block to the map and create a new nextBlock
      numBlocks++;
      numOnScreen++;
      nextBlock->setOnBoard(true); // put nextblock on the Board
      nextBlock->set(nextBlock->getType(), numBlocks + 1); // set the types of the cells of the block
      bmap[numBlocks] = move(nextBlock);
      nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false)); // make the next block
    } else {
      g->setGameOver(true);
    }
  }
  return increasedscore;
}

// replace the current undropped block
void Board::replaceBlock(string s) {
  if (isHintActivated) { unsetHint(hintcells);}
  // replace the block at bmap[numBlocks]
  bmap[numBlocks]->unset();
  bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true, s));
}

void Board::hint() {
  int highestScore = 0;
  int currentScore = 0;
  int shift = 0;
  int rotate = 0;
  int origstate = bmap[numBlocks]->getCurrState();
  Coordinate origleftref = bmap[numBlocks]->getLeftRef();
  map<int, vector<Coordinate>> states = bmap[numBlocks]->getStates();
  int currstate;
  int lowestleft;
  vector<Cell*> origcells = bmap[numBlocks]->getBlockCells();
  vector<Cell*> tempcells = bmap[numBlocks]->getBlockCells();

  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 3; j++) {
      currentScore = drop(true);
      currstate = bmap[numBlocks]->getCurrState();
      for (int k = 0; k < 4; ++k) {
        Coordinate c = states[currstate][k];
        tempcells[k] = g->getCell(c.row, c.col + i);
      }
      bmap[numBlocks]->setBlockCells(tempcells);
      bmap[numBlocks]->setLeftRef(origleftref.row+2, origleftref.col + i);
      bmap[numBlocks]->updateStates();
      states = bmap[numBlocks]->getStates();
      lowestleft = 0;
      if (currentScore > highestScore) {
        highestScore = currentScore;
        shift = i;
        rotate = j;
      } else if (currentScore == highestScore) {

      }
      rotateCW(true);
    }
    shift = i;
    if (!moveRight(true)) {
      break;
    }
  }

  bmap[numBlocks]->setBlockCells(origcells);
  bmap[numBlocks]->setLeftRef(origleftref.row, origleftref.col);
  bmap[numBlocks]->setCurrState(origstate);
  for (int i = 0; i < shift; i++) {
    moveRight(true);
  }
  for (int i = 0; i < rotate; i++) {
    rotateCW(true);
  }
  // copy the position of the hint to the hintcells vector
  drop(true);
  hintcells = bmap[numBlocks]->getBlockCells();

  for (int i = 0; i < 4; ++i) {
    hintcells[i]->set("?", -1);
  }

  isHintActivated = true;
  bmap[numBlocks]->setBlockCells(origcells); // set the currblock back to the original cells
  bmap[numBlocks]->setLeftRef(origleftref.row, origleftref.col);
  bmap[numBlocks]->setCurrState(origstate);
}

void Board::unsetHint(vector<Cell*> hintcells) {
  isHintActivated = false;
  for (unsigned int i = 0; i < hintcells.size(); ++i) {
    hintcells[i]->unset();
  }
}

void Board::random() {
  if (isHintActivated) { unsetHint(hintcells);}
  if (level == 3) {
    l = make_unique<L3>(seed, false);
    bmap[numBlocks]->unset();
    nextBlock->unset();
    bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true));
    nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false));
  } else if (level == 4) {
    l = make_unique<L3>(seed, true);
    bmap[numBlocks]->unset();
    nextBlock->unset();
    bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true));
    nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false));
  }
}

void Board::norandom(string filename) {
  if (isHintActivated) { unsetHint(hintcells);}
  if (level == 3) {
    l = make_unique<L3>(false, filename);
    bmap[numBlocks]->unset();
    nextBlock->unset();
    bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true));
    nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false));
  } else if (level == 4) {
    l = make_unique<L3>(true, filename);
    bmap[numBlocks]->unset();
    nextBlock->unset();
    bmap[numBlocks] = move(l->createBlock(g.get(), numBlocks, true));
    nextBlock = move(l->createBlock(g.get(), numBlocks + 1, false));
  }
}

// CHANGE LEVEL
// increases the level
void Board::levelUp() {
  if (isHintActivated) { unsetHint(hintcells);}
  if ((level + 1) <= 4) { level += 1; }
  bmap[numBlocks]->unset();
  nextBlock->unset();
  init(); // create the new level
}

// decreases the level
void Board::levelDown() {
  if (isHintActivated) { unsetHint(hintcells);}
  if ((level - 1) >= 0) { level -= 1; }
  bmap[numBlocks]->unset();
  nextBlock->unset();
  init(); // create the new level
}
