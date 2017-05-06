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
  // 玩家被吃时，不会执行相应操作
  if(g_isBeEat != 0)
  {
    return;
  }
  m_nType = CGame::itemRoad;
  g_nAddScore += g_nPeanBeEatScore;
  ++g_nEatPeanNum;
}
