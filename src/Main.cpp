// Main.cpp : Defines the entry point for the application.

#include "Include/Game.h"
#include <iostream>

using namespace std;

Game* game = NULL;

void Init(void)
{
  game = new Game();
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glClearColor(0.11, 0.11, 0.11, 0.99);
  glShadeModel(GL_SMOOTH); // Enable Smooth Shading
  glClearDepth(1.0f); // Depth Buffer Setup
  glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
}

void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  game -> Draw();
  glFlush();
  glutSwapBuffers();
}

void Reshape(int width, int height)
{
  glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, 0, height, -10, 10);
  glMatrixMode(GL_MODELVIEW);
}

void OnKeyPress(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27: // esc key
    {
      if(game != NULL)
        delete game;
      exit(0);
    }
  }
}

void OnMouseAction(int button, int state, int x, int y)
{
  y = WINDOW_HEIGHT - y;
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    game -> OnMouseDown(x, y);
  else
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    game -> OnMouseUp(x, y);
}

void OnMouseMove(int x, int y)
{
  y = WINDOW_HEIGHT - y;
  game -> OnMouseMove(x, y);
}

void OnContextMenu(int option)
{
  if(option == 1)
  {
    if(game != NULL)
      delete game;
    game = new Game();
    glutPostRedisplay();
  }
  else
  if(option == 2)
  {
    if(game != NULL)
      delete game;
    exit(0);
  }
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  glutCreateMenu(OnContextMenu);
  glutAddMenuEntry("New Game", 1);
  glutAddMenuEntry("Exit", 2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  Init();
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(OnKeyPress);
  glutMouseFunc(OnMouseAction);
  glutMotionFunc(OnMouseMove);
  glutIdleFunc(NULL);
  glutDisplayFunc(Display);
  glutMainLoop();
  if (game != NULL)
    delete game;
  return 0;
}