#pragma once
#include "pacMan.h"
#include "staticObj.h"

class CGhoHome :
  public CStaticObj
{
public:
  CGhoHome(int nRow, int nCol);
  virtual ~CGhoHome();
  virtual IGameElement* creatSelf(int nRow, int nCol);
};

