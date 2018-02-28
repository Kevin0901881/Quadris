#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include "commandinterpreter.h"
#include "left.h"
#include "right.h"
#include "down.h"
#include "rotatecw.h"
#include "rotateccw.h"
#include "drop.h"
#include "levelup.h"
#include "leveldown.h"
#include "random.h"
#include "norandom.h"
#include "restart.h"
#include "hint.h"


using namespace std;

// CommandInterpreter read, parses, and executes a command or a series of commands

CommandInterpreter::CommandInterpreter(Board* board, string scriptfile) :
  board{board}, scriptfile{scriptfile} {
  createCommands();
  autoComplete = make_unique<AutoComplete>(listOfCommands);
  switchBlocks = false; // if the input is L, J, I, O, S, Z, T then switchBlocks becomes true
}

void CommandInterpreter::readInput() { // reads the input from stdin
  cin >> currentInput;
}

void CommandInterpreter::readInput(string nextCommand) { // reads the input given next command (from file)
  currentInput = nextCommand;
}

void CommandInterpreter::parseInput() { // processes the input taken from readInput()
  int count = 1;
  multiplier = 0;
  while (currentInput.front() >= '0' && currentInput.front() <= '9') { // checks if the first character is a number (multiplier)
    multiplier = (multiplier * count) + (currentInput.front() - '0'); // sets the multiplier
    currentInput.erase(0, 1); // removes the first character in the input, getting only the command name
    count *= 10;
  }

  // if no given multiplier, then set multiplier to 1
  if (count == 1) {
     multiplier = 1;
  }

  if (currentInput != "L" && currentInput != "J" && currentInput != "O" && currentInput != "I" &&
    currentInput != "T" && currentInput != "Z" && currentInput != "S") {
    currentInput = autoComplete->completeCommand(currentInput);
    for (auto& cmd : listOfCommands) {
      if (cmd.first == currentInput) { // matches input with the command names in listOfCommands
        command = cmd.second;
        break;
      }
    }
  }
}

void CommandInterpreter::execute() { // executes the command
  if (currentInput == "L" || currentInput == "J" || currentInput == "O" || currentInput == "I" ||
    currentInput == "T" || currentInput == "Z" || currentInput == "S") {
    board->replaceBlock(currentInput); // sets the current block according to the input
  } else {
    for (int i = 0; i < multiplier; i++) { // applies multiplier to execute
      if (currentInput == "norandom") { // when command is norandom, read in the filename and execute the command
        cin >> scriptfile;
        command = make_shared<NoRandom>(board, scriptfile);
        command->execute();
      } else if (currentInput == "sequence") { // when command is sequence, create another commandinterpreter object pointer
        cin >> sequencefile;
        unique_ptr<CommandInterpreter> sequenceInterpreter = make_unique<CommandInterpreter>(board, scriptfile); // creates a new CommandInterpreter pointer
        string word;
        ifstream infile(sequencefile); // opens the sequence file
        while (infile >> word) { // reads the file one command at a time
          sequenceInterpreter->readInput(word);
          try {
            sequenceInterpreter->parseInput();
            sequenceInterpreter->execute();
          } catch (string s) {
            cerr << s << endl;
          }
        }
        infile.close(); // close the file at the end
      } else {
        command->execute();
      }
    }
  }
}

void CommandInterpreter::createCommands() { // pushes the command names and command pointers into the list of commands
  listOfCommands.emplace("left", make_shared<Left>(board));
  listOfCommands.emplace("right", make_shared<Right>(board));
  listOfCommands.emplace("down",  make_shared<Down>(board));
  listOfCommands.emplace("clockwise", make_shared<RotateCW>(board));
  listOfCommands.emplace("counterclockwise", make_shared<RotateCCW>(board));
  listOfCommands.emplace("drop",  make_shared<Drop>(board));
  listOfCommands.emplace("levelup", make_shared<LevelUp>(board));
  listOfCommands.emplace("leveldown", make_shared<LevelDown>(board));
  listOfCommands.emplace("random", make_shared<Random>(board));
  listOfCommands.emplace("restart", make_shared<Restart>(board));
  listOfCommands.emplace("hint", make_shared<Hint>(board));
}
