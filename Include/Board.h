#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include "Bitmap.h"
#include "BoardColumn.h"
#include "Dice.h"

class Board
{
private:
	BoardColumn* columns[24];
	Dice*        dice[2];
  Bitmap*      background;
  void Cleanup();
public:
	Board();
	virtual ~Board();
	void Draw();
  void NewGame();
};