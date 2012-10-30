#pragma once

class Point
{
private:
	int x, y;
  
public:
	Point(int x, int y)
	{
		this -> x = x;
		this -> y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
};