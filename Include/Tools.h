#ifndef TOOLS_DEFINED
#define TOOLS_DEFINED

#define WINDOW_WIDTH 592
#define WINDOW_HEIGHT 475

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

enum GameStatus { W_PLAYING, B_PLAYING, W_ROLLING, B_ROLLING, W_TO_THROW, B_TO_THROW, W_NO_MOVES, B_NO_MOVES };

#endif