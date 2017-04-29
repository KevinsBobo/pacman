#ifndef CGAMECTRLHEADER
#define CGAMECTRLHEADER
#pragma once

#include "pacMan.h"

class CGameCtrl
{
public:
  // 单例类创建函数
  SINGLE_INSTANCE_STAT(CGameCtrl);

  void gameStart();
  void gameLoop();

  // 检查状态
  int checkStatus();

  // 当玩家吃掉超级豆
  void whenPlayerEatSuperPean();
  // 当玩家碰撞恐惧时的鬼
  void whenPlayerEatGhost();
  // 当玩家碰撞正常鬼
  void whenGhostEatPlayer();

private:
  CGameCtrl();
  virtual ~CGameCtrl();

  CGetCGameUI*   m_getUIObj;
  CGetCGameMap*  m_getMapObj;
  CGameUI*       m_uiObj;
  CGameMap*      m_mapObj;
  IGameElement** m_moveObj;
  CGhost**       m_ghostObj;
  CPlayer*       m_playerObj;
};

// 创建单例类的类
CREATE_SINGLE_OBJ(CGameCtrl);

#endif // CGAMECTRLHEADER