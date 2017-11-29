#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"

class Level {
public:
  virtual Block* createBlock() = 0;
};

#endif
