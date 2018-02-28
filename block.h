#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "coordinate.h"
#include "cell.h"

class Grid;

class Block {
  int counter = 0;
  std::string type;
  int level;
  bool onBoard;
protected:
  Grid* g;
  Coordinate leftRef;
  std::map<int, std::vector<Coordinate>> states; // hold the different states a block can have
  std::vector<Cell*> cells;
  int width;
  int height;
  int heavy;
  int currState = 0;
  int numStates;
  int ID;

public:
  // pure virtual functions to be overridden by derived classes
  virtual ~Block() = 0;
  virtual void updateStates() = 0;

  // default methods for all blocks
  // MAINTENANCE METHODS
  virtual void addCell(Coordinate c);
  virtual void removeCell(Coordinate c);
  virtual bool isEmpty();
  virtual std::vector<Coordinate> createCoords();
  virtual void updateCounter();

// TODO : CHANGE DROP TO NOT REMOVECELLS IF HINT

  // SETTERS
  virtual void set(std::string, int blockid);
  virtual void setBlockCells(std::vector<Cell*>);
  virtual void setLevel(int lvl);
  virtual void setHeaviness();
  virtual void setType(std::string btype);
  virtual void setOnBoard(bool onBoard);
  virtual void setID(int blockid);
  virtual void setWidth(int w);
  virtual void setHeight(int h);
  virtual void setLeftRef(int r, int c);
  virtual void setCurrState(int x);
  virtual void setNumStates(int x);
  virtual void unset();

  // GETTERS
  virtual std::string getType();
  virtual int getHeaviness();
  virtual int getLevel();
  virtual int getHeight();
  virtual Coordinate getLeftRef();
  virtual std::vector<Cell*> getBlockCells();
  virtual int getCurrState();
  virtual int getNumStates();
  virtual std::map<int, std::vector<Coordinate>> getStates();

  // MOVE METHODS
  virtual bool inBlock(int, int);
  virtual bool isValidShift(std::string dir);
  virtual bool shift(std::string dir, bool isDrop, bool isHint);
  virtual bool isValidRotate(std::string dir);
  virtual void rotate(std::string dir, bool isHint);
  virtual void drop(bool isHint);
};

#endif
