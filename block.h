#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block {
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
public:
  virtual ~Block() = 0;
  virtual void init() = 0;
  virtual int getLevel();
  virtual std::vector<Cell*> getCells();
  //virtual void setCoord() = 0;
  virtual bool isEmpty();
  virtual bool isValidMove();  
  virtual void rotateCW() = 0;
  virtual void rotateCCW() = 0;
  virtual void moveLeft();
  virtual void moveRight();
  virtual void moveDown();
  virtual void drop();
  virtual void draw();
  virtual void unset();
  virtual void updateCounter();
};

#endif
