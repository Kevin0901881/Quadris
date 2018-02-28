#ifndef NODE_H
#define NODE_H
#include <vector>
#include <memory>

struct Node {
  std::vector<std::unique_ptr<Node>> child;
  bool end; // end = true if the node is the last letter of the command

  Node() : child(26), end{false} {}
};

#endif
