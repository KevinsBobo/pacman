#include "moveObj.h"


CMoveObj::CMoveObj()
  : CGameElement() , m_nSpead(0) , m_nPreMoveClock(0)
{
}

CMoveObj::CMoveObj(int nRow , int nCol)
  : CGameElement(nRow, nCol) , m_nSpead(0) , m_nPreMoveClock(0)
{
  m_nPreMoveClock = -1 ^ (1 << (sizeof(clock_t) * 8 - 1));
}

CMoveObj::~CMoveObj()
{
}

// 更新时间，并返回时间是否大于对象速度
int CMoveObj::updateClock()
{
  return 0;
}


// 移动
int CMoveObj::move()
{
  return 0;
}
