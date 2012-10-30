// Main.cpp : Defines the entry point for the application.

#include "Include/Board.h"
#include <iostream>

using namespace std;

Board* board = NULL;

void Init(void)
{
  board = new Board();
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glClearColor(0.3, 0.0, 0.0, 0.0);
}

void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT); 
  board -> Draw();  
  glFlush();
  glutSwapBuffers();
}

void Reshape(int w, int h)
{
  glutReshapeWindow(592, 394);
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, w, 0, h, -10.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

void OnKeyPress(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27: //ESC
      exit(0);
  }
}

void OnMouseAction(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // DEBUG PURPOSES ONLY ;)
    exit(0);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(592, 394);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  Init();
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(OnKeyPress);
  glutMouseFunc(OnMouseAction);
  glutDisplayFunc(Display);
  glutMainLoop();
  
  if(board != NULL)
    delete board;
  return 0;
}