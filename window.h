#ifndef WINDOW_H
#define WINDOW_H
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
  Display* d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[10];
public:
  Xwindow(int width=720, int height=720);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.
  Xwindow(const Xwindow&) = delete;
  Xwindow &operator=(const Xwindow&) = delete;

  enum {White=0, Black, Plum, Salmon, Khaki, PaleGreen, MediumAquamarine, LightSkyBlue, SandyBrown,
    MediumPurple};
    // White is background of actual grid.
    //Black is colour of rest of background and ?
    // Plum is colour of J
    // Salmon is colour of O
    // Khaki is colour of S
    //PaleGreen is colour of Z
    // MediumAquamarine is colour of I
    // LightSkyBlue is colour of L
    // SandyBrown is colour of *
    // MediumPurple is colour of text and T


  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // Draws a string
  void drawString(int x, int y, std::string msg, int colour=Black);

  // Show all available fonts
  void showAvailableFonts();

  //draw borders
  void drawBorder(int x1, int y1, int x2, int y2, int colour);
};


#endif
