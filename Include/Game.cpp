#include "Game.h"

Game::Game()
{
  status = W_TO_THROW;
  board = new Board();
  statusBar = new StatusBar();
  activeChecker = NULL;
}

Game::~Game()
{
  if(board != NULL)
    delete board;
  if(statusBar != NULL)
    delete statusBar;
}

void Game::Draw()
{
  statusBar -> Draw(status, dice1, dice2);
  LightsOn();
  board -> Draw();
  LightsOff();
  if(status == W_ROLLING || status == B_ROLLING)    
    Dice::StartRolling();
  if(activeChecker != NULL)
  {
    LightsOn();
    activeChecker -> Draw();
    LightsOff();
  }
}

void Game::OnMouseDown(int x, int y)
{
  if(status == W_NO_MOVES || status == B_NO_MOVES)
  {
    status = status == W_NO_MOVES ? B_TO_THROW : W_TO_THROW;
    glutPostRedisplay();
    return;
  }
  else
  if(status == W_TO_THROW || status == B_TO_THROW)
  {
    status = status == W_TO_THROW ? W_ROLLING : B_ROLLING;
    glutPostRedisplay();
  }
  else
  if(status == W_ROLLING || status == B_ROLLING)
  {
    Dice::StopRolling();
    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;    
    status = status == W_ROLLING ? W_PLAYING : B_PLAYING;
    
    if(!board -> HasValidMove(status, dice1, dice2))
    {
      status = status == W_ROLLING ? W_NO_MOVES : B_NO_MOVES;
      glutPostRedisplay();
      return;
    }
    if(dice1 == dice2)
      movesLeft = 4 * dice1;
    else
      movesLeft = dice1 + dice2;
    
    glutPostRedisplay();
  }
  else
  if(status == W_PLAYING || status == B_PLAYING)
  {
    activeChecker = board -> GetPendingChecker(status);
    if(activeChecker != NULL)
      return;
    
    activeChecker = board -> GetChecker(x, y, &activeColumnIndex);
    if(activeChecker == NULL || status == W_PLAYING && !activeChecker -> IsWhite() || 
       status == B_PLAYING && activeChecker -> IsWhite())
    {
      activeChecker = NULL;
      return;
    }
    board -> RemoveLastFromColumn(activeColumnIndex);
  }
}

void Game::OnMouseUp(int x, int y)
{
  bool isWhite = status == W_PLAYING;
  bool isBlack = status == B_PLAYING;
  if(isWhite || isBlack)
  {
    if(activeChecker == NULL)
      return;
    int dicePlayed = -1;
    
    int newColumn = -1;
    Checker* currentChecker = board -> GetChecker(x, y, &newColumn);
    
    bool validMove = currentChecker == NULL || currentChecker -> IsWhite() && isWhite || !currentChecker -> IsWhite() && isBlack;
    int destCheckersCount = board -> getCheckersCountInColumn(newColumn);
    
    if(isWhite)
    {
      if(activeChecker -> isPending())
        activeColumnIndex = 23;
      dicePlayed = activeColumnIndex - newColumn;
    }
    else
    {
      if(activeChecker -> isPending())
        activeColumnIndex = 0;
      dicePlayed = newColumn - activeColumnIndex;    
    }
    
    if(activeChecker -> isPending())
    {     
      bool positionValid = isBlack && newColumn < 6 && newColumn >= 0 || isWhite && newColumn > 17 && newColumn < 24;
      if(newColumn >= 0 && positionValid && (validMove || destCheckersCount == 1))
      {
        if((dicePlayed + 1) == dice1)
        {
          movesLeft -= dice1;
          dice1 = -1;
          std::cout<<movesLeft<<endl;
        }
        else
        if((dicePlayed + 1) == dice2)
        {       
          movesLeft -= dice2;
          dice2 = -1;
          std::cout<<movesLeft<<endl;
        }
        else
          newColumn = -1;

          std::cout<<movesLeft<<endl;
        if(!validMove && destCheckersCount == 1)
          board -> MoveToPendingCheckers(status, newColumn);
        board -> AddToColumn(status, newColumn);
        activeColumnIndex = newColumn;        
      }
      else
      {
        board -> MoveToPendingCheckers(isWhite ? B_PLAYING : W_PLAYING, activeChecker);  
        activeChecker = NULL;
      }
    }
    else
    if(newColumn < 0 || !validMove && destCheckersCount != 1)
      board -> AddToColumn(status, activeColumnIndex);
    else
    {
      if(dice1 > 0 && dicePlayed == dice1)
      {
        movesLeft -= dice1;
        dice1 = -1;
      }
      else
      if(dice2 > 0 && dicePlayed == dice2)
      {
        movesLeft -= dice2;
        dice2 = -1;
      }
      else
        dicePlayed = -1;
        
      if(dicePlayed > 0)
      {
        if(destCheckersCount == 1 && !validMove)
          board -> MoveToPendingCheckers(status, newColumn);
        board -> AddToColumn(status, newColumn);
        activeColumnIndex = newColumn;
      }
      else
        board -> AddToColumn(status, activeColumnIndex);
    }
    
    if(movesLeft == 0)
      status = isWhite ? B_TO_THROW : W_TO_THROW;
    
    if(activeChecker != NULL)
    {
      delete activeChecker;
      activeChecker = NULL;
    }
    glutPostRedisplay();
  }
}

void Game::OnMouseMove(int x, int y)
{
  if(activeChecker == NULL)
    return;
  activeChecker -> SetCenter(new Point(x, y));
  glutPostRedisplay();
}

void Game::LightsOn()
{
  GLfloat ambientLight[]  = { 0.4, 0.4, 0.4, 1.0 }; //цвета на Ambient светлината
  GLfloat diffuseLight[]  = { 0.8, 0.8, 0.8, 1.0 }; // цвета на Diffuse светлината
  GLfloat lightPosition[] = { 1.0, 1.0, 0, 0.0 }; // позиция на светлинния източник

  glEnable(GL_LIGHTING); //включваме динамична светлина
  //определяме глобална Ambient светлина
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
  glEnable(GL_LIGHT0); //включваме светлинен източник
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight); //определя Diffuse излъчването
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
  
  //определяме начина, по който обектите поглъщат светлина от тип Ambient и Diffuse
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseLight);

  glEnable(GL_COLOR_MATERIAL); //цвета на обектите, се запазва
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);//цвета на обекта да участва в получаването на крайния цвят
  
}

void Game::LightsOff()
{
  glDisable(GL_LIGHTING); //изключваме динамична светлина
  glDisable(GL_LIGHT0); //изключваме светлинен източник
  glDisable(GL_COLOR_MATERIAL);
}