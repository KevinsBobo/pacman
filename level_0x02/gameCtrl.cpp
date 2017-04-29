#include "gameCtrl.h"

// 单例类创建函数
SINGLE_INSTANCE(CGameCtrl);

CGameCtrl::CGameCtrl()
{
  m_getUIObj = new CGetCGameUI;
  m_getMapObj = new CGetCGameMap;
  m_uiObj = m_getUIObj->get();
  m_mapObj = m_getMapObj->get();
  m_moveObj = m_mapObj->getMoveObj();
  m_ghostObj = (CGhost**)m_mapObj->getMoveObj();
  m_playerObj = (CPlayer*)m_moveObj[ g_nGhost ];

  g_gameMap = m_mapObj;
}


CGameCtrl::~CGameCtrl()
{
  delete m_getUIObj;
  delete m_getMapObj;
  g_gameMap = NULL;
}

void CGameCtrl::gameStart()
{

}

void CGameCtrl::gameLoop()
{
  static clock_t nPreTime = 0;
  static const clock_t nRefreshTime = 100;
  static clock_t nowTime = 0;
  static char ch;

  while(1)
  {
    if(_kbhit())
    {
      ch = _getch();
      switch(ch)
      {
        case 'w':
        case 'W':
          m_playerObj->changeAction(CGame::actUp);
          break;
        case 'a':
        case 'A':
          m_playerObj->changeAction(CGame::actLeft);
          break;
        case 's':
        case 'S':
          m_playerObj->changeAction(CGame::actDown);
          break;
        case 'd':
        case 'D':
          m_playerObj->changeAction(CGame::actRight);
          break;
      }
    }

    nowTime = clock();
    if(nowTime - nRefreshTime < nPreTime)
    {
      continue;
    }
    nPreTime = nowTime;

    m_mapObj->show(m_uiObj , &CGameUI::echoMap);
    
    for(int i = 0; i < g_nGhost + g_nPlayer; ++i)
    {
      m_moveObj[ i ]->move();
    }

    if(checkStatus() == 1)
    {
      break;
    }
  }
}

// 检查状态
int CGameCtrl::checkStatus()
{
  m_playerObj->addScore(g_nAddScore);

  if(g_isBeEat == 1)
  {
    whenGhostEatPlayer();
  }
  else if(g_nGhostBeEat == 1)
  {
    whenPlayerEatGhost();
  }
  else if(g_nSuperPeanBeEat)
  {
    whenPlayerEatSuperPean();
  }

  if(m_playerObj->getLift() == 0)
  {
    return 1;
  }

  return 0;
}

// 当玩家吃掉超级豆
void CGameCtrl::whenPlayerEatSuperPean()
{

}

// 当玩家碰撞恐惧时的鬼
void CGameCtrl::whenPlayerEatGhost()
{

}

// 当玩家碰撞正常鬼
void CGameCtrl::whenGhostEatPlayer()
{
  // todo...

  // 玩家、鬼回位
  for(int i = 0; i < g_nGhost + g_nPlayer; ++i)
  {
    ((CMoveObj*)m_moveObj[ i ])->backPos();
  }

  g_isBeEat = 0;
}

// 创建单例类的类
CREATE_SINGLE_OBJ_REALIZE(CGameCtrl);