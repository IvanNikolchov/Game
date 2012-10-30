#pragma once
#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

enum Color  { WHITE,  BLACK };
enum Status { INGAME, ONBAR, SUCCEEDED };

class Checker
{	
	Color color;
	Status status;	
public:	
	Checker();
	~Checker();
};

