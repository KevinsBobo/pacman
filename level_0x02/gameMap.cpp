#include "pacMan.h"

int g_map[ MAPROW ][ MAPCOL ] =
{
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
  1,2,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,2,1,
  1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,
  1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,
  1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,1,1,1,4,4,1,1,1,0,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,1,4,4,4,4,4,4,1,0,1,1,0,1,1,1,1,1,1,
  0,0,0,0,0,0,0,0,0,0,1,4,4,4,4,4,4,1,0,0,0,0,0,0,0,0,0,0,
  1,1,1,1,1,1,0,1,1,0,1,4,4,4,4,4,4,1,0,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,
  1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
  1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
  1,2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,2,1,
  1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,
  1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,
  1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,
  1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
  1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int g_nFirstGhoRow = 14;
const int g_nFirstGhoCol = 12;

const int g_nPlayerRow = 23;
const int g_nPlayerCol = 13;

CGameMap::CGameMap()
{
  int nRow = 0;
  int nCol = 0;
  for(nRow = 0; nRow < g_nMapRow ; ++nRow)
  {
    for(nCol = 0; nCol < g_nMapCol ; ++nCol)
    {
      switch(g_map[ nRow ][ nCol ])
      {
        case CGame::itemPean:
          m_gameObj[ nRow * g_nMapCol + nCol ] = new CPean(nRow , nCol);
          break;
        case CGame::itemWall:
          m_gameObj[ nRow * g_nMapCol + nCol ] = new CWall(nRow , nCol);
          break;
        case CGame::itemSurperPean:
          m_gameObj[ nRow * g_nMapCol + nCol ] = new CSuperPean(nRow , nCol);
          break;
        case CGame::itemRoad:
          m_gameObj[ nRow * g_nMapCol + nCol ] = new CRoad(nRow , nCol);
          break;
        case CGame::itemGhoHome:
          m_gameObj[ nRow * g_nMapCol + nCol ] = new CGhoHome(nRow , nCol);
          break;
      }
    }
  }
  
  int nGhoCol = g_nFirstGhoCol;
  nCol = 0;
  for(int i = 0; i < g_nGhost; ++i, ++nCol, ++nGhoCol)
  {
    m_gameObj[ nRow * g_nMapCol + nCol ] = new CGhost(g_nFirstGhoRow , nGhoCol);
  }

  m_gameObj[ nRow * g_nMapCol + nCol ] = new CPlayer(g_nPlayerRow , g_nPlayerCol);
}


CGameMap::~CGameMap()
{
  for(int i = 0; i < MAPROW * MAPCOL + NGHOST + NPLAYER; ++i)
  {
    delete m_gameObj[ i ];
  }
}

void CGameMap::show(echoMapElement echoFun)
{
  static CGameUI echoObj;
  for(int i = 0; i < MAPROW * MAPCOL + NGHOST + NPLAYER; ++i)
  {
    (echoObj.*echoFun)((*m_gameObj[ i ])[ CGame::posRow ] ,
                       (*m_gameObj[ i ])[ CGame::posCol ] ,
                        m_gameObj[ i ]->getType());
  }
}
