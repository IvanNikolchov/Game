#pragma once
#include "Include/Tools.h"
#include "Checker.h"
#include <vector>

using namespace std;

class BoardColumn
{
	vector<Checker*>* checkers;
	Point* upperLeft;
	Point* lowerRight;
	
public:
	BoardColumn();
	~BoardColumn();
  void Draw();
};