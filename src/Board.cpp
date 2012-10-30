#include "Include/Bitmap.h"
#include "Include/Board.h"
#include "Include/Checker.h"
#include <iostream>

const Point Board::upLeft(62, 456);
const Point Board::downLeft(62, 266);
const Point Board::upRight(310, 456);
const Point Board::downRight(310, 266);
const int   Board::columnHeight = 170;
const int   Board::columnWidth = 37;
const int   Board::checkersTemplate[] = { 2, 0, 0, 0, 0, 5, 0, 3, 0, 0, 0, 5, 5, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 2 };
const Color Board::colorsTemplate[]   = { BLACK, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK,
                                            WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, WHITE };

Board::Board()
{
  background = new Bitmap("Images/Board.bmp");
  
  glGenTextures(1, &backgroundTextureId);
  glBindTexture(GL_TEXTURE_2D, backgroundTextureId);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, background -> getWidth(), background -> getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, background->getData());
  
  columns[0] = NULL;
  NewGame();
}

Board::~Board()
{
  glDeleteTextures(1, &backgroundTextureId);
  if(background != NULL)
    delete background;
  Cleanup();
}

void Board::Cleanup()
{
  if(columns[0] != NULL)
  {
    for(int i = 0; i < 24; ++i)
    {
      columns[i]->Dispose();
      delete columns[i];
      columns[i] = NULL;
    }
    for(int i = 0; i < pendingWhites -> size(); ++i)
      delete pendingWhites -> at(i);
    
    for(int i = 0; i < pendingBlacks -> size(); ++i)
      delete pendingBlacks -> at(i);
    
    delete pendingWhites;
    delete pendingBlacks;
    
    pendingWhites = NULL;
    pendingBlacks = NULL;
  }
}

void Board::NewGame()
{
  Cleanup();
  pendingWhites = new vector<Checker*>();
  pendingBlacks = new vector<Checker*>();
  int index = 0;
  
  for(int j = 0; j < 2; ++j)
  {
    Point point = j == 0 ? upRight : upLeft;
    for(int i = 5; i >= 0; --i, ++index)
    {
      Point* upLeftCorner = new Point(point.getX() + columnWidth * i, point.getY());
      Point* bottomRightCorner = new Point(upLeftCorner->getX() + columnWidth, upLeftCorner -> getY() - columnHeight);
      columns[index] = new BoardColumn(upLeftCorner, bottomRightCorner, checkersTemplate[index], colorsTemplate[index], index);
    }
  }
  
  for(int j = 0; j < 2; ++j)
  {
    Point point = j == 0 ? downLeft : downRight;
    for(int i = 0; i <= 5; ++i, ++index)
    {
      Point* upLeftCorner = new Point(point.getX() + columnWidth * i, point.getY());
      Point* bottomRightCorner = new Point(upLeftCorner->getX() + columnWidth, upLeftCorner -> getY() - columnHeight);
      columns[index] = new BoardColumn(upLeftCorner, bottomRightCorner, checkersTemplate[index], colorsTemplate[index], index);
    }
  }
}

void Board::Draw()
{
  glLoadIdentity();
  glColor3f(0.99, 0.99, 0.99);
  
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, backgroundTextureId);
  glBegin(GL_QUADS);
    glTexCoord2i(0, 0);
    glVertex3i(0, 80, -10);
    glTexCoord2i(0, 1);
    glVertex3i(0, 80 + background -> getHeight(), -10);
    glTexCoord2i(1, 1);
    glVertex3i(background -> getWidth(), 80 + background -> getHeight(), -10);
    glTexCoord2i(1, 0);
    glVertex3i(background -> getWidth(), 80, -10);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
  for(int i = 0; i < 24; ++i)
    columns[i] -> Draw();
  
  for(int i = 0; i < pendingBlacks -> size(); ++i)
    pendingBlacks -> at(i) -> Draw();
  
  for(int i = 0; i < pendingWhites -> size(); ++i)
    pendingWhites -> at(i) -> Draw();
}

Checker* Board::GetChecker(int x, int y, int* activeColumnIndex)
{
  *activeColumnIndex = -1;
  for(int i = 0; i < 24; ++i)
  {
    BoardColumn* column = columns[i];
    if(column -> IsInside(x, y))
    {
      *activeColumnIndex = column -> getIndex();
      return column -> PeekLastChecker();
    }
  }
  return NULL;
}

int Board::getCheckersCountInColumn(int columnIndex)
{
  if(columnIndex >= 0 && columnIndex < 24)
    return columns[columnIndex] -> getCheckersCount();
  return -1;
}

void Board::MoveToPendingCheckers(GameStatus status, int columnIndex)
{
  Checker* pendingChecker = RemoveLastFromColumn(columnIndex);
  MoveToPendingCheckers(status, pendingChecker);
}

void Board::MoveToPendingCheckers(GameStatus status, Checker* pendingChecker)
{
  pendingChecker -> setPending(true);
  int y = 60;
  if(status == W_PLAYING)
  {
    int size = pendingBlacks -> size();
    int x = 30 + 10 + size * 2 * (Checker::RADIUS + 5);
    pendingBlacks -> push_back(pendingChecker);
    pendingChecker -> SetCenter(new Point(x, y));
  }
  else
  {
    int size = pendingWhites -> size();
    int x = WINDOW_WIDTH - 30 - size * 2 * (Checker::RADIUS + 5);
    pendingWhites -> push_back(pendingChecker);
    pendingChecker -> SetCenter(new Point(x, y));
  }
}

Checker* Board::GetPendingChecker(GameStatus status)
{
  vector<Checker*>* pendingList = status == W_PLAYING ? pendingWhites : pendingBlacks;
  if(pendingList -> empty())
    return NULL;
  Checker* pendingChecker = pendingList -> back();
  pendingList -> pop_back();
  return pendingChecker;  
}

Checker* Board::RemoveLastFromColumn(int columnIdx)
{
  if(columnIdx >= 0 && columnIdx < 24)
    columns[columnIdx] -> PopLastChecker();
}

bool checkDice(BoardColumn** columns, Checker* checker, GameStatus status, int columnIndex, int dice)
{
  int newColumnIndex;
  if(status == W_PLAYING)
    newColumnIndex = columnIndex - dice;
  else
    newColumnIndex = columnIndex + dice;

  if(newColumnIndex < 24 && newColumnIndex >= 0)
  {
    BoardColumn* newColumn = columns[newColumnIndex];
    Checker* lastChecker = newColumn -> PeekLastChecker();
    if(lastChecker == NULL || lastChecker -> IsWhite() == checker -> IsWhite())
      return true;
  }
  return false;
}

bool Board::HasValidMove(GameStatus status, int dice1, int dice2)
{
  for(int i = 0; i < 24; ++i)
  {
    BoardColumn* column = columns[i];
    int columnIndex = i;
    Checker* checker = column -> PeekLastChecker();
    if(checker == NULL)
      continue;
    
    if(checker -> IsWhite() && status == W_PLAYING || 
      !checker -> IsWhite() && status == B_PLAYING)
    {
      if(checkDice(columns, checker, status, columnIndex, dice1))
        return true;
      if(checkDice(columns, checker, status, columnIndex, dice2))
        return true;
    }
  }
  return false;
}

void Board::AddToColumn(GameStatus status, int columnIndex)
{
  Color color = status == W_PLAYING ? WHITE : BLACK;  
  columns[columnIndex] -> AddChecker(color);
}