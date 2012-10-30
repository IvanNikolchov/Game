#ifndef GAME_DEFINED
#define GAME_DEFINED

#include "Board.h"
#include "StatusBar.h"
#include "Checker.h"
#include "Tools.h"
class Game
{
public:
  Game();
  virtual ~Game();
  void Draw();
  void OnMouseDown(int x, int y);
  void OnMouseUp(int x, int y);
  void OnMouseMove(int x, int y);
  
private:
  void LightsOn();
  void LightsOff();
  GameStatus status;
  Board* board;
  StatusBar* statusBar;
  int dice1;
  int dice2;
  Checker* activeChecker;
  int movesLeft;
  int activeColumnIndex;
};

#endif