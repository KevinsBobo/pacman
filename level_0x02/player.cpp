#include "player.h"


CPlayer::CPlayer(int nRow , int nCol)
  : CMoveObj(nRow , nCol) , m_nScore(0)
{
  m_nType = CGame::itemPlayer;
  m_nAction = CGame::actUp;
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
