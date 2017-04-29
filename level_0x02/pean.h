#pragma once
#include "pacMan.h"
#include "staticObj.h"

class CPean :
  public CStaticObj
{
public:
  CPean(int nRow, int nCol);
  virtual ~CPean();
  virtual IGameElement* creatSelf(int nRow, int nCol);
};

