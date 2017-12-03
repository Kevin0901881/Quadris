#include <string>
#include <vector>
#include <map>
#include <memory>
#include "autocomplete.h"
#include "command.h"

using namespace std;

// AutoComplete is a class that returns a full command name given a portion of a command name (prefix).
// It implements the trie data structure to minimize time complexity and adds a few features that wouldn't
// be possible without using this structure or through hard coding all input possibilities, such as word
// suggestion (i.e. typing 'le' yields left, levelup, leveldown)

AutoComplete::AutoComplete(map<string, unique_ptr<Command>> &listOfCommands) {
  createDefaultTrie(listOfCommands); // when an AutoComplete object is create the data structure is automatically
                       // generated based on the default commands
}

void AutoComplete::createDefaultTrie(map<string, unique_ptr<Command>> &listOfCommands) { // called when AutoComplete is initialized
  for (auto cmd : listOfCommands) { // calls insert to create the trie
    insert(cmd.first);
  }
  insert("norandom"); // inserts norandom and sequence since they aren't part of listOfCommands
  insert("sequence");
}

void AutoComplete::insert(const string &s) { // inserts a command name into the trie
  unique_ptr<Node> currentNode = rootNode;
  for (char c : s) { // gets each letter in the string s
    if (c >= 'A' && c <= 'Z') { // determines whether the character is capitalized or not
      c = c + 32;
    }
    if (currentNode->child[c - 'a'] == nullptr) { // if the character matches, the move on to the next node,
                                                  // otherwise, create a new node at that character index
      currentNode->child[c - 'a'] = make_unique<Node>();
    } else {
      currentNode = currentNode->child[c - 'a'];
    }
    currentNode->end = false;
  }
  currentNode->end = true; // at the last node, set the 'end' field to true to indicate last letter in the word
}

string AutoComplete::completeCommand(string &s) { // returns the full name of the command in the parameter
  unique_ptr<Node> currentNode = rootNode;
  for (char c : s) {
    if (c >= 'A' && c <= 'Z') { // determines whether the character is capitalized or not
      c = c + 32;
    }
    if (currentNode->child[c - 'a'] == nullptr) { // if the inputted command is longer than an actual command,
                                                  // or if it is not a prefix of an actual command, thow an exception
      throw "Invalid command";
    }
    currentNode = currentNode->child[c - 'a'];
  }
  while (!currentNode->end) { // if the current node isn't the last character in the command, then complete the rest
    for (int i = 0; i < 26; i++) { // since each node contains 26 children representing the letters in the alphabet,
                                   // loop through the alphabet to find the next letter in the command
      if (currentNode->child[i] != nullptr) {
        s += i + 'a';
        currentNode = currentNode->child[i];
        break;
      }
    }
  }
  return s; // return the full command  name
}
