#include "Include/Checker.h"
#include "Include/Bitmap.h"
#include <math.h>

Checker::Checker(Color color, Point* leftColumnCorner, Point* rightColumnCorner, int multiplier, bool direction)
{
  this -> color = color;
  this -> pending = false;
  int x = leftColumnCorner -> getX() + RADIUS + 1;
  int y = 0;
  int yDiff = RADIUS * (2 * multiplier + 1) + 2 + 4 * multiplier;
  
  if(direction)
    y = rightColumnCorner -> getY() + yDiff;
  else
    y = leftColumnCorner -> getY() - yDiff;
  
  this -> center = new Point(x, y);
}

Checker::~Checker()
{
  if(this -> center != NULL)
    delete this -> center;
}

void Checker::Draw()
{
  GLint slices = 100, stacks = 100;
  
  glPushMatrix();
  if(color == WHITE)
    glColor3f(213/256.0, 146/256.0, 59/256.0);
  else
    glColor3f(57/256.0, 32/256.0, 21.0/256.0);

  glTranslatef(center -> getX(), center -> getY(), 0);
  glRotatef(20, 1, 0, 0);
  glutSolidCylinder(RADIUS, 15, slices, stacks);
  DrawCircle();  
  glPopMatrix();
}

void Checker::DrawCircle()
{
  float delta_theta = 0.01;
  glBegin( GL_POLYGON );  
  for( float angle = 0; angle < 2 * M_PI; angle += delta_theta)
    glVertex3f(RADIUS * cos(angle), RADIUS * sin(angle), 0);
  glEnd();
}

void Checker::SetCenter(Point* center)
{
  if(this -> center != NULL) 
    delete this -> center; 
  this -> center = center;
}