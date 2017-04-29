#pragma once
#include "pacMan.h"
#include "staticObj.h"

class CRoad :
  public CStaticObj
{
public:
  CRoad(int nRow, int nCol);
  virtual ~CRoad();
  virtual IGameElement* creatSelf(int nRow, int nCol);
};

