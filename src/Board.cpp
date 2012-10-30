#include "Include/Bitmap.h"
#include "Include/Board.h"
#include <iostream>
Board::Board()
{
  //background = new Bitmap("D:\\My Documents\\Visual Studio 2010\\Projects\\Backgammon\\Backgammon\\Images\\Board.bmp");
  background = new Bitmap("Images/Board.bmp");
  NewGame();
}

Board::~Board()
{
  if(background != NULL)
    delete background;
  Cleanup();
}

void Board::Cleanup()
{
  if(dice[0] != NULL)
  {
    delete dice[0];
    delete dice[1];
    dice[0] = NULL;
    dice[1] = NULL;
    for(int i = 0; i < 24; ++i)
    {
      delete columns[i];
      columns[i] = NULL;
    }
  }
}

void Board::NewGame()
{
  Cleanup();
  dice[0] = new Dice();
  dice[1] = new Dice();
  for(int i = 0; i < 24; ++i)
    columns[i] = new BoardColumn();
}

void Board::Draw()
{
  glColor3f(1.0, 1.0, 1.0);  
  glLoadIdentity();
  glRasterPos2i(0, 0);
  glDrawPixels(background -> getWidth(), background -> getHeight(), GL_BGR_EXT, GL_UNSIGNED_BYTE, background -> getData());
  
  for(int i = 0; i < 24; ++i)
    columns[i] -> Draw();
}