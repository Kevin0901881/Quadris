#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
#include "coordinate.h"

class Cell {
  int row, col; //coordinates of cell in the graphicdisplay
  int id; // the block ID
  std::string blockType; //type of block the cell belongs to
  bool onBoard;
  bool hint;

public:
  Cell(int r, int c); //constructor. takes in 2 int to set the coord

  std::string getBlockType(); //returns the type of block the cell belongs to
  Coordinate getCoord(); //return coord struct
  void set(std::string b, int blockid); //sets the blockType field from Block b
  void unset(); //unsets the blockType field to None
  bool isOccupied(); //checks if the cell belongs to any Block
  void moveDown(); //increases row field by 1
  void setID(int blockid); // sets the block ID of the cell
  int getID(); // return the block ID of the cell
  void setOnBoard(bool ob);
  bool getOnBoard() const;
  friend std::ostream &operator<<(std::ostream &out, const Cell &c);

};

#endif
