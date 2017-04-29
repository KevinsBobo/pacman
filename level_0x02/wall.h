#pragma once
#include "pacMan.h"
#include "staticObj.h"

class CWall :
  public CStaticObj
{
public:
  CWall(int nRow, int nCol);
  virtual ~CWall();
  virtual IGameElement* creatSelf(int nRow, int nCol);
};

