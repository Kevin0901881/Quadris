#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include "board.h"
#include "command.h"
#include "autocomplete.h"

class CommandInterpreter : public Game {
  Board* board;
  std::unique_ptr<Command> command;
  std::unique_ptr<AutoComplete> autoComplete; // used to get the full name of a command
  std::map<std::string, unique_ptr<Command>> listOfCommands;
  std::string currentInput;
  int multiplier = 1;
  std::string scriptfile;
  std::string sequencefile;
  bool switchBlocks;
public:
  CommandInterpreter(Board* board, std::string scriptfile); // constructor
  void readInput(); // reads input from stdin
  void readInput(std::string nextCommand); // reads input given next command (from file)
  void parseInput(); // completes the command if necessary and adds inputs to listOfCommands
  void execute(); // executes the command invoked by the input
  void createCommands(); // populates the listOfCommands
};

#endif
