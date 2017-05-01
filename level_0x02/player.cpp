#include "player.h"


CPlayer::CPlayer(int nRow , int nCol)
  : CMoveObj(nRow , nCol) , m_nScore(1) , m_nlife(g_nPlayerlife)
{
  m_nType = CGame::itemPlayer;
  m_nAction = CGame::actLeft;
  m_nSpead = g_nInitPlayerSpead;
}


CPlayer::~CPlayer()
{
}


IGameElement* CPlayer::creatSelf(int nRow, int nCol)
{
  return NULL;
}

int CPlayer::getScore()
{
  return m_nScore;
}

void CPlayer::setScore(int nScore)
{
  m_nScore = nScore;
}

void CPlayer::addScore(int nScore)
{
  m_nScore += nScore;
}

int CPlayer::getlife()
{
  return m_nlife;
}

void CPlayer::setlife(int nlife)
{
  m_nlife = nlife;
}

void CPlayer::beHit()
{
    g_isBeEat = 1;
    m_nlife -= 1;
}

// 更新时间，并返回时间是否大于对象速度
int CPlayer::updateClock()
{
  clock_t nowTime = clock();
  if(nowTime - m_nSpead >= m_nPreMoveClock)
  {
    m_nPreMoveClock = nowTime;
    return 1;
  }
  return 0;
}

// 回位
void CPlayer::backPos()
{
  m_nAction = CGame::actLeft;
  m_postion.set(g_nPlayerRow, g_nPlayerCol);
}
