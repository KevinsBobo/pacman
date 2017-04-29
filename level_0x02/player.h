#pragma once
#include "pacMan.h"
#include "moveObj.h"

class CPlayer :
  public CMoveObj
{
public:
  CPlayer(int nRow, int nCol);
  virtual ~CPlayer();
  virtual IGameElement* creatSelf(int nRow, int nCol);
  int getScore();
  
private:
  int m_nScore;
};

