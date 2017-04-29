#include "road.h"


CRoad::CRoad(int nRow, int nCol)
  : CStaticObj(nRow, nCol)
{
  m_nType = CGame::itemRoad;
}


CRoad::~CRoad()
{
}


IGameElement* CRoad::creatSelf(int nRow, int nCol)
{
  return NULL;
}
