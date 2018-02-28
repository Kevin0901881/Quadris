#ifndef SCORE_H
#define SCORE_H

class Block;

class TextDisplay;

class Score {
  int currentScore = 0;
  int highScore = 0;
public:
  int blockClear(Block*, bool isHint);
  int rowClear(int, int, bool isHint);
  void updateScore(int);
  void restart();
  void reset();
  int getCurrentScore();
  int getHiScore();
};

#endif
