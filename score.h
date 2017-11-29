#ifndef SCORE_H
#define SCORE_H

class Score {
  int currentScore = 0;
  int highScore = 0;
public:
  void setScore();
  int getCurrentScore();
  int getHiscore();
};

#endif
