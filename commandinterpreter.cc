#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include "commandinterpreter.h"

using namespace std;

// CommandInterpreter read, parses, and executes a command or a series of commands
// TODO: add macro, rename

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
  if (currentInput.front() >= '0' && currentInput.front() <= '9') { // checks if the first character is a number (multiplier)
    multiplier = stoi(currentInput.front()); // sets the multiplier
    currentInput.erase(0, 1); // removes the first character in the input, getting only the command name
  }
  if (currentInput != "L" && currentInput != "J" && currentInput != "O" && currentInput != "I" &&
    currentInput != "T" && currentInput != "Z" && currentInput != "S") {
    currentInput = autoComplete->completeCommand(currentInput);
    for (auto cmd : listOfCommands) {
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
        command = make_unique<NoRandom>(board.get(), scriptfile);
        command->execute();
      } else if (currentInput == "sequence") { // when command is sequence, create another commandinterpreter object pointer
        cin >> sequencefile;
        unique_ptr<CommandInterpreter> sequenceInterpreter = make_unique<CommandInterpreter>(board.get(), scriptfile); // creates a new CommandInterpreter pointer
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
  // push all the default commands into the vector of command names
  // listOfCommands.emplace("left", make_unique<Left>(board);
  // listOfCommands.emplace("right", make_unique<Right>(board);
  // listOfCommands.emplace("down", make_unique<Down>(board);
  // listOfCommands.emplace("clockwise", make_unique<ClockWise>(board);
  // listOfCommands.emplace("counterclockwise", make_unique<CounterClockWise>(board);
  // listOfCommands.emplace("drop", make_unique<Drop>(board);
  // listOfCommands.emplace("levelup", make_unique<LevelUp>(board);
  // listOfCommands.emplace("leveldown", make_unique<LevelDown>(board);
  // listOfCommands.emplace("random", make_unique<Random>(board);
  // listOfCommands.emplace("restart", make_unique<Restart>(board);
  // listOfCommands.emplace("hint", make_unique<Hint>(board);
  listOfCommands.emplace("left", make_unique<Left>(board.get()));
  listOfCommands.emplace("right", make_unique<Right>(board.get()));
  listOfCommands.emplace("down",  make_unique<Down>(board.get()));
  listOfCommands.emplace("clockwise", make_unique<ClockWise>(board.get()));
  listOfCommands.emplace("counterclockwise", make_unique<CounterClockWise>(board.get()));
  listOfCommands.emplace("drop",  make_unique<Drop>(board.get()));
  listOfCommands.emplace("levelup", make_unique<LevelUp>(board.get()));
  listOfCommands.emplace("leveldown", make_unique<LevelDown>(board.get()));
  listOfCommands.emplace("random", make_unique<Random>(board.get()));
  listOfCommands.emplace("restart", make_unique<Restart>(board.get()));
  listOfCommands.emplace("hint", make_unique<Hint>(board.get()));
}
