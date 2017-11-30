#ifndef SCORE_H
#define SCORE_H

class Score {
  int currentScore = 0;
  int highScore = 0;
public:
  int blockClear();
  int rowClear();
  void updateScore();
  void restart();
  void reset();
  int getCurrentScore();
  int getHiScore();
};

#endif
