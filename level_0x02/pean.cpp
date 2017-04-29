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

void CPean::beHit()
{
  m_nType = CGame::itemRoad;
  g_nAddScore += g_nPeanBeEatScore;
}
