#ifndef BOARD_DEFINED
#define BOARD_DEFINED

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include "Bitmap.h"
#include "BoardColumn.h"
#include "Dice.h"
#include "StatusBar.h"
#include "Tools.h"
#include <vector>

class Board
{
private:
  static const Point upLeft;
  static const Point downLeft;
  static const Point upRight;
  static const Point downRight;
  static const int checkersTemplate[24];
  static const Color colorsTemplate[24];
	static const int columnHeight;
  static const int columnWidth;
  
  BoardColumn* columns[24];
  vector<Checker*>* pendingWhites;
  vector<Checker*>* pendingBlacks;
  Bitmap*      background;  
  GLuint backgroundTextureId;
  void Cleanup();
  void NewGame();
public:  
	Board();
	virtual ~Board();
	void Draw();
  Checker* GetChecker(int x, int y, int* activeColumnIndex);
  Checker* RemoveLastFromColumn(int columnIdx);
  Checker* GetPendingChecker(GameStatus status);
  bool HasValidMove(GameStatus status, int dice1, int dice2);
  void AddToColumn(GameStatus status, int columnIndex);
  int getCheckersCountInColumn(int columnIndex);
  void MoveToPendingCheckers(GameStatus status, int columnIndex);
  void MoveToPendingCheckers(GameStatus status, Checker* pendingChecker);
};

#endif