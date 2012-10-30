#include "Include/Dice.h"
#include <cstdlib>
#include <iostream>

float Dice::rotationAngle1 = 0.0f;
float Dice::rotationAngle2 = 55.5f;

void Draw(float& rotationAngle)
{
  // Clear Screen And Depth Buffer
  glTranslatef(0.0f, 0.0f, 0.0f);
  glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Rotate The cube around the Y axis
  glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f);

  glBegin(GL_QUADS); // Draw The Cube Using quads
    //1
    glColor3f(0.99, 0.99, 0.99);
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f); 
    //2
    glVertex3f(1.0f, -1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f); 
    //3
    glVertex3f(1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f); 
    //4
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f); 
    //5
    glVertex3f(1.0f, 1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    //6
    glVertex3f(1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f); 

    glColor3f(0.1f, 0.1f, 0.1f); 
    //1
    glVertex3f(-1.1f, 0.2f, 0.2f); 
    glVertex3f(-1.1f, 0.2f, -0.2f); 
    glVertex3f(-1.1f, -0.2f, -0.2f); 
    glVertex3f(-1.1f, -0.2f, 0.2f); 

    //2
    glVertex3f(0.4f, -1.1f, -0.4f); 
    glVertex3f(0.4f, -1.1f, -0.8f); 
    glVertex3f(0.8f, -1.1f, -0.8f); 
    glVertex3f(0.8f, -1.1f, -0.4f); 

    glVertex3f(-0.8f, -1.1f, 0.8f); 
    glVertex3f(-0.8f, -1.1f, 0.4f); 
    glVertex3f(-0.4f, -1.1f, 0.4f); 
    glVertex3f(-0.4f, -1.1f, 0.8f); 

    //3
    glVertex3f(0.2f, 0.2f, -1.1f); 
    glVertex3f(0.2f, -0.2f, -1.1f); 
    glVertex3f(-0.2f, -0.2f, -1.1f); 
    glVertex3f(-0.2f, 0.2f, -1.1f); 

    glVertex3f(0.4f, -0.4f, -1.1f); 
    glVertex3f(0.4f, -0.8f, -1.1f); 
    glVertex3f(0.8f, -0.8f, -1.1f); 
    glVertex3f(0.8f, -0.4f, -1.1f); 

    glVertex3f(-0.8f, 0.8f, -1.1f); 
    glVertex3f(-0.8f, 0.4f, -1.1f); 
    glVertex3f(-0.4f, 0.4f, -1.1f); 
    glVertex3f(-0.4f, 0.8f, -1.1f); 

    //4
    glVertex3f(0.4f, -0.4f, 1.1f); 
    glVertex3f(0.4f, -0.8f, 1.1f); 
    glVertex3f(0.8f, -0.8f, 1.1f); 
    glVertex3f(0.8f, -0.4f, 1.1f); 

    glVertex3f(-0.4f, -0.4f, 1.1f); 
    glVertex3f(-0.4f, -0.8f, 1.1f); 
    glVertex3f(-0.8f, -0.8f, 1.1f); 
    glVertex3f(-0.8f, -0.4f, 1.1f); 

    glVertex3f(-0.8f, 0.8f, 1.1f); 
    glVertex3f(-0.8f, 0.4f, 1.1f); 
    glVertex3f(-0.4f, 0.4f, 1.1f); 
    glVertex3f(-0.4f, 0.8f, 1.1f); 

    glVertex3f(0.8f, 0.8f, 1.1f); 
    glVertex3f(0.8f, 0.4f, 1.1f); 
    glVertex3f(0.4f, 0.4f, 1.1f); 
    glVertex3f(0.4f, 0.8f, 1.1f); 

    //5
    glVertex3f(0.4f, 1.1f, -0.4f); 
    glVertex3f(0.4f, 1.1f, -0.8f); 
    glVertex3f(0.8f, 1.1f, -0.8f); 
    glVertex3f(0.8f, 1.1f, -0.4f); 

    glVertex3f(-0.4f, 1.1f, -0.4f); 
    glVertex3f(-0.4f, 1.1f, -0.8f); 
    glVertex3f(-0.8f, 1.1f, -0.8f); 
    glVertex3f(-0.8f, 1.1f, -0.4f); 

    glVertex3f(-0.8f, 1.1f, 0.8f); 
    glVertex3f(-0.8f, 1.1f, 0.4f); 
    glVertex3f(-0.4f, 1.1f, 0.4f); 
    glVertex3f(-0.4f, 1.1f, 0.8f); 

    glVertex3f(0.8f, 1.1f, 0.8f); 
    glVertex3f(0.8f, 1.1f, 0.4f); 
    glVertex3f(0.4f, 1.1f, 0.4f); 
    glVertex3f(0.4f, 1.1f, 0.8f); 

    glVertex3f(0.2f, 1.1f, 0.2f); 
    glVertex3f(0.2f, 1.1f, -0.2f); 
    glVertex3f(-0.2f, 1.1f, -0.2f); 
    glVertex3f(-0.2f, 1.1f, 0.2f); 

    //6
    glVertex3f(1.1f, 0.4f, -0.4f); 
    glVertex3f(1.1f, 0.4f, -0.8f); 
    glVertex3f(1.1f, 0.8f, -0.8f); 
    glVertex3f(1.1f, 0.8f, -0.4f); 

    glVertex3f(1.1f, -0.4f, -0.4f); 
    glVertex3f(1.1f, -0.4f, -0.8f); 
    glVertex3f(1.1f, -0.8f, -0.8f); 
    glVertex3f(1.1f, -0.8f, -0.4f); 

    glVertex3f(1.1f, -0.8f, 0.8f); 
    glVertex3f(1.1f, -0.8f, 0.4f); 
    glVertex3f(1.1f, -0.4f, 0.4f); 
    glVertex3f(1.1f, -0.4f, 0.8f); 

    glVertex3f(1.1f, 0.8f, 0.8f); 
    glVertex3f(1.1f, 0.8f, 0.4f); 
    glVertex3f(1.1f, 0.4f, 0.4f); 
    glVertex3f(1.1f, 0.4f, 0.8f); 

    glVertex3f(1.1f, 0.4f, 0.2f); 
    glVertex3f(1.1f, 0.4f, -0.2f); 
    glVertex3f(1.1f, 0.8f, -0.2f); 
    glVertex3f(1.1f, 0.8f, 0.2f); 

    glVertex3f(1.1f, -0.4f, 0.2f); 
    glVertex3f(1.1f, -0.4f, -0.2f); 
    glVertex3f(1.1f, -0.8f, -0.2f); 
    glVertex3f(1.1f, -0.8f, 0.2f); 

  glEnd();

  rotationAngle += 0.8f; // Increase Angle  
}

unsigned char * buff;
void DrawDices()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glLoadIdentity(); // Reset The Current Modelview Matrix  
  glTranslatef(5.5f, -14.0f, -40.0f); // Translate Into The Screen 7.0 Units
  Draw(Dice::rotationAngle1);
  glLoadIdentity(); // Reset The Current Modelview Matrix
  glTranslatef(8.5f, -14.0f, -40.0f); // Translate Into The Screen 7.0 Units
  Draw(Dice::rotationAngle2);
  
  glLoadIdentity();
  glTranslatef(-17.96f, -16.96f, -21.0f);
  glRasterPos3i(1, 0, -20);
  glEnable(GL_TEXTURE_2D);
  glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_BGR, GL_UNSIGNED_BYTE, buff);
  glDisable(GL_TEXTURE_2D);
  
  glFlush();
  glutSwapBuffers(); 
}
void Dice::StartRolling()
{
  int size = 3 * WINDOW_WIDTH * WINDOW_HEIGHT;
  buff = new unsigned char[size];
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glReadPixels(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GL_BGR, GL_UNSIGNED_BYTE, buff);
  
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
  glLoadIdentity(); // Reset The Projection Matrix
  gluPerspective(45.0f, (GLfloat) WINDOW_WIDTH / (GLfloat) WINDOW_WIDTH, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix  
  glutIdleFunc(DrawDices);
}

void Dice::StopRolling()
{
  glutIdleFunc(NULL);  
  delete buff;
  glDisable(GL_DEPTH_TEST);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -10.0, 50.0);
  glMatrixMode(GL_MODELVIEW);
  
  Dice::rotationAngle1 = 0.0f;
  Dice::rotationAngle2 = 55.5f;
}