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
  // 当玩家吃完所有豆子
  void whenAllPeanBeEat();
  // 检查玩家分数、升级鬼
  void checkPlayerScore();

  // 改变鬼的方向
  void changeGhostAct();

  // 寻路算法
  int findAction(CPostion srcPos, CPostion dstPos, int nAct);

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