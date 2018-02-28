#include <cmath>
#include "score.h"
#include "block.h"

using namespace std;

// calculate score when a block is cleared
int Score::blockClear(Block* b, bool isHint) {
  int lvl = b->getLevel();
  int bscore = pow(lvl + 1, 2);
  if (!isHint) { updateScore(bscore); }// update the current score
  return bscore;
}

// calculate score when line(s) are cleared
int Score::rowClear(int rowsCleared, int currLevel, bool isHint) {
  int rscore = pow(currLevel + rowsCleared, 2);
  if (!isHint) { updateScore(rscore); } // update the current score
  return rscore;
}

// add to the current score (and maybe high score)
void Score::updateScore(int score) {
  currentScore += score;

  // check if the current score has exceeded high score
  // if so, then update highscore
  if (currentScore > highScore) {
    highScore = currentScore;
  }
}

// restart the game and set current score to 0
void Score::restart() {
  currentScore = 0;
}

// reset the scores
void Score::reset() {
  currentScore = 0;
}

// retrieve the current score
int Score::getCurrentScore() {
  return currentScore;
}

// retrieve the high score
int Score::getHiScore() {
  return highScore;
}
