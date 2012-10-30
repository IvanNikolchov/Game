#ifndef STATUSBAR_DEFINED
#define STATUSBAR_DEFINED

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "Tools.h"
#include <iostream>

using namespace std;

class StatusBar
{
public:
  StatusBar();
  virtual ~StatusBar();
  void Draw(GameStatus status, int dice1, int dice2);
private:
  void glutPrintText(float x, float y, string text);
};

#endif