#include "pean.h"


CPean::CPean(int nRow, int nCol)
  : CStaticObj(nRow, nCol)
{
  m_nType = CGame::itemPean;
}


CPean::~CPean()
{
}


IGameElement* CPean::creatSelf(int nRow, int nCol)
{
  return NULL;
}
