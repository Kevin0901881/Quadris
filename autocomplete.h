#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "node.h"
#include "command.h"

class AutoComplete {
  vector<std::string> commands;
  unique_ptr<Node> rootNode;
  void createDefaultTrie(std::map<std::string, unique_ptr<Command>> &listOfCommands); // creates a trie given a list of commands
  void insert(const std::string &s); // inserts a string into a trie
public:
  AutoComplete(std::map<std::string, unique_ptr<Command>> &listOfCommands); // constructor
  std::string completeCommand(std::string &s); // autocompletes the command given a prefix
};

#endif
