#include "Include/Game.h"
#include <string>
StatusBar::StatusBar()
{
}

StatusBar::~StatusBar()
{
}

void StatusBar::Draw(GameStatus status, int dice1, int dice2)
{
  glColor3f(255/256.0, 255/256.0, 255/256.0);
  
  switch(status)
  {
    case W_PLAYING:
    {
      string diceStr("White to play: ");
      if(dice1 > 0)
      {
        diceStr += ('0' + dice1);
        diceStr += " ";
      }
      if(dice2 > 0)
        diceStr += ('0' + dice2);
      glutPrintText(10, 10, diceStr);
      break;
    }
    case B_PLAYING:
    {
      string diceStr("Black to play: ");
      if(dice1 > 0)
      {
        diceStr += ('0' + dice1);
        diceStr += " ";
      }
      if(dice2 > 0)
        diceStr += ('0' + dice2);
      glutPrintText(10, 10, diceStr);
      break;
    }
    case W_TO_THROW:
      glutPrintText(10, 10, "White, click to start rolling");
      break;
    case B_TO_THROW:
      glutPrintText(10, 10, "Black, click to stasrt rolling");
      break;
    case W_ROLLING:
      glutPrintText(10, 10, "White, click to throw dice");
      break;
    case B_ROLLING:
      glutPrintText(10, 10, "Black, click to throw dice");
      break;
    case W_NO_MOVES:
    {
      string diceStr("White to play: ");
      if(dice1 > 0)
      {
        diceStr += ('0' + dice1);
        diceStr += " ";
      }
      if(dice2 > 0)
        diceStr += ('0' + dice2);
      diceStr += " but there are no valid moves! Click to continue.";
      glutPrintText(10, 10, diceStr);
      break;
    }
    case B_NO_MOVES:
    {
      string diceStr("White to play: ");
      if(dice1 > 0)
      {
        diceStr += ('0' + dice1);
        diceStr += " ";
      }
      if(dice2 > 0)
        diceStr += ('0' + dice2);
      diceStr += " but there are no valid moves! Click to continue.";
      glutPrintText(10, 10, diceStr);      
      break;
    }
  }
}

void StatusBar::glutPrintText(float x, float y, string text)
{
  glRasterPos3f(x, y, 1.0);
  for (int idx = 0; idx < text.length(); idx++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[idx]);
}