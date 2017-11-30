#include <cmath>
#include "score.h"

using namespace std;

// calculate score when a block is cleared
void Score::blockClear(Block b) {
  int lvl = b.getLevel();
  int bscore = pow(lvl + 1, 2);
  setScore(bscore); // update the current score
}

// calculate score when line(s) are cleared
int Score::rowClear(int rowsCleared, int currLevel) {
  int rscore = pow(currLevel + rowsCleared, 2);
  setScore(rscore); // update the current score
}

// add to the current score (and maybe high score)
void Score::updateScore(int x) {
  currentScore += x;

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
  highScore = 0;
}

// retrieve the current score
int Score::getCurrentScore() {
  return currentScore;
}

// retrieve the high score
int Score::getHiscore() {
  return highScore;
}
