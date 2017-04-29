#include "ghoHome.h"


CGhoHome::CGhoHome(int nRow, int nCol)
  : CStaticObj(nRow, nCol)
{
  m_nType = CGame::itemGhoHome;
}


CGhoHome::~CGhoHome()
{
}


IGameElement* CGhoHome::creatSelf(int nRow, int nCol)
{
  return NULL;
}
