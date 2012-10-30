#ifndef DICE_DEFINED
#define DICE_DEFINED

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "Tools.h"

class Dice
{
private:
  Dice() { }
public:
  static float rotationAngle1;
  static float rotationAngle2;
	static void StartRolling();  
  static void StopRolling();
};

#endif