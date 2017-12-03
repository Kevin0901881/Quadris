#ifndef NODE_H
#define NODE_H
#include <vector>
#include <memory>

struct Node {
  std::vector<unique_ptr<Node>> child(26); // creates a vector of size 26 representing the alphabet
  bool end; // end = true if the node is the last letter of the command
};

#endif
