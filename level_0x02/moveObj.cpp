#include "moveObj.h"


CMoveObj::CMoveObj()
  : CGameElement() , m_nSpead(0) , m_nPreMoveClock(0)
{
}

CMoveObj::CMoveObj(int nRow , int nCol)
  : CGameElement(nRow, nCol) , m_nSpead(0) , m_nPreMoveClock(0)
{
  // 错误，将初始速度设为最大会导致逻辑错误
  // m_nPreMoveClock = -1 ^ (1 << (sizeof(clock_t) * 8 - 1));
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
  // 当玩家被鬼抓到的时候晚间就不能再动了
  // 这个用于解决在岔路口时鬼检测到了抓到玩家，
  // 而玩家却没有检测到被鬼抓到
  // 因为逻辑上是鬼先于玩家移动的，所以鬼不会出现这种问题
  if(m_nType == CGame::itemPlayer && g_isBeEat == 1)
  {
    return 0;
  }

  if(updateClock() == 0)
  {
    return 0;
  }
  int nCrash = isCrash();
  if(nCrash == CGame::craPass)
  {
    m_postion = m_postion.getActionPostion(m_nAction);
  }

  // 检查死鬼是否回家
  if(m_nType == CGame::itemGhoDie)
  {
    if(m_postion[ CGame::posRow ] == g_nFirstGhoRow &&
       m_postion[ CGame::posCol ] >= g_nFirstGhoCol - 1 &&
       m_postion[ CGame::posCol ] <= g_nFirstGhoCol + g_nGhost)
    {
      m_nType = CGame::itemGhoNormal;
      m_nSpead += 100;
    }
  }

  return 0;
}

// 设置速度
void CMoveObj::setSpead(int nSpead)
{
  m_nSpead = nSpead;
}

clock_t CMoveObj::getSpead()
{
  return m_nSpead;
}

// 回位
void CMoveObj::backPos()
{

}

// 获取方向
int CMoveObj::getAction()
{
  return m_nAction;
}
