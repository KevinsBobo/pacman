#pragma once
#include "pacMan.h"
#include "staticObj.h"

class CSuperPean :
  public CStaticObj
{
public:
  CSuperPean(int nRow, int nCol);
  virtual ~CSuperPean();
  virtual IGameElement* creatSelf(int nRow, int nCol);
};

