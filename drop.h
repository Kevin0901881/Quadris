#ifndef DROP_H
#define DROP_H
#include <memory>

class Drop : public Command {
  Board* board;
public:
  Drop(Board* b); // constructor
  void execute(); // executes the drop command
};

#endif
