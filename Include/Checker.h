#ifndef CHECKER_DEFINED
#define CHECKER_DEFINED
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "Tools.h"

enum Color  { WHITE,  BLACK };
enum Status { INGAME, ONBAR, SUCCEEDED };

class Checker
{
private:
  Color color;
	Status status;
  Point* center;
  bool pending;
  
public:
  static const int RADIUS = 15;
	Checker(Color color, Point* leftColumnCorner, Point* rightColumnCorner, int multiplier, bool direction);
	~Checker();
  void Draw();
  void DrawCircle();
  bool IsWhite() { return color == WHITE; }
  void SetCenter(Point* center);
  bool isPending() { return pending; }
  void setPending(bool pending) { this -> pending = pending; }
};

#endif