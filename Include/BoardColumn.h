#ifndef BOARDCOLUMN_DEFINED
#define BOARDCOLUMN_DEFINED

#include "Include/Tools.h"
#include "Checker.h"
#include <vector>

using namespace std;

class BoardColumn
{
	vector<Checker*>* checkers;
	Point* upperLeft;
	Point* lowerRight;
  int quadrant;
  int index;
  
public:
	BoardColumn(Point* upperLeft, Point* lowerRight, int numberOfCheckers, Color initialColor, int index);
	~BoardColumn();
  void Draw();
  void Dispose();
  int getCheckersCount() { return checkers -> size(); }
  bool IsInside(int x, int y);
  Checker* PeekLastChecker() { return checkers -> empty() ? NULL : checkers -> back(); }
  Checker* PopLastChecker();
  void AddChecker(Color color);
  int getIndex() { return index; }
};

#endif