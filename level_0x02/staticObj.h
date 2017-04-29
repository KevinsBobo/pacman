#ifndef CSTATICOBJHEDAER
#define CSTATICOBJHEDAER
#pragma once
#include "pacMan.h"
#include "gameElement.h"

class CStaticObj :
  public CGameElement
{
public:
  CStaticObj();
  CStaticObj(int nRow , int nCol);
  virtual ~CStaticObj();
};

#endif // CSTATICOBJHEDAER