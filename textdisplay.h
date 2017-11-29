#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>


class TextDisplay {
  std::vector<std::vector<char>> theDisplay;

public:
 TextDisplay();
 void drawCell();
 void drawScore();
 void clear();

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);


};

#endif
