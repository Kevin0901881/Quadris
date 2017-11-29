#ifndef GRAPHICDISPLAY_H__
#define GRAPHICDISPLAY_H__
#include "window.h"

class GraphicDisplay {

  XWindow xw;
public:
  GraphicDisplay();
  void drawCell();
  void drawScore();
  void clear();
};


#endif
