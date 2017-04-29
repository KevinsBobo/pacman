#include "wall.h"


CWall::CWall(int nRow, int nCol)
  : CStaticObj(nRow, nCol)
{
  m_nType = CGame::itemWall;
}


CWall::~CWall()
{
}


IGameElement* CWall::creatSelf(int nRow, int nCol)
{
  return NULL;
}
