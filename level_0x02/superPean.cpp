#include "superPean.h"


CSuperPean::CSuperPean(int nRow, int nCol)
  : CStaticObj(nRow, nCol)
{
  m_nType = CGame::itemSurperPean;
}


CSuperPean::~CSuperPean()
{
}


IGameElement* CSuperPean::creatSelf(int nRow, int nCol)
{
  return NULL;
}
