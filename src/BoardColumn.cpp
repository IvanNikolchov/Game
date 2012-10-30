#include "Include/BoardColumn.h"
#include "Include/Board.h"
#include <math.h>

BoardColumn::BoardColumn(Point* upperLeft, Point* lowerRight, int numberOfCheckers, Color initialColor, int index)
{
  checkers = new vector<Checker*>();
  this -> quadrant = index / 6;
  this -> index = index;
  this -> upperLeft = upperLeft;
  this -> lowerRight = lowerRight;
  for (int i = 0; i < numberOfCheckers; ++i)
    checkers -> push_back(new Checker(initialColor, upperLeft, lowerRight, i, quadrant > 1));
}

BoardColumn::~BoardColumn()
{
  if (checkers == NULL)
    return;
  for (int i = 0; i < checkers->size(); ++i)
    delete checkers -> at(i);
  delete checkers;
  delete upperLeft;
  delete lowerRight;
}

void BoardColumn::Draw()
{
  glColor3f(1, 1, 1);
/*
  glBegin(GL_LINES);
  glColor3f(0.99, 0, 0);
  glVertex3d(upperLeft->getX(), upperLeft->getY(), 10);
  glVertex3d(lowerRight->getX(), upperLeft->getY(), 10);
  glColor3f(0, 0.99, 0);
  glVertex3d(lowerRight->getX(), upperLeft->getY(), 10);
  glVertex3d(lowerRight->getX(), lowerRight->getY(), 10);
  glColor3f(0, 0, 0.99);
  glVertex3d(lowerRight->getX(), lowerRight->getY(), 10);
  glVertex3d(upperLeft->getX(), lowerRight->getY(), 10);
  glColor3f(0.99, 0.99, 0.99);
  glVertex3d(upperLeft->getX(), lowerRight->getY(), 10);
  glVertex3d(upperLeft->getX(), upperLeft->getY(), 10);
  glEnd();
*/
  for (int i = 0; i < checkers -> size(); ++i)
    checkers -> at(i) -> Draw();
}

void BoardColumn::Dispose()
{
}

bool BoardColumn::IsInside(int x, int y)
{
  return upperLeft -> getX() <= x &&
          upperLeft -> getY() >= y &&
          lowerRight -> getX() >= x &&
          lowerRight -> getY() <= y;
}

Checker* BoardColumn::PopLastChecker()
{
  if(checkers -> empty())
    return NULL;
  Checker* last = checkers -> back();
  checkers -> pop_back();
  return last;
}

void BoardColumn::AddChecker(Color color)
{  
  Checker* checker = new Checker(color, upperLeft, lowerRight, checkers -> size(), quadrant > 1);
  checkers -> push_back(checker);
}