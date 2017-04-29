#ifndef CGAMEMAPHEADER
#define CGAMEMAPHEADER
#pragma once
#include "pacMan.h"

class CGameMap
{
public:

  // 单例类创建函数
  SINGLE_INSTANCE_STAT(CGameMap);

  void show(CGameUI* uiObj, echoMapElement echoFun);

  IGameElement** operator[](int nIndex);

  IGameElement** getMoveObj();

private:
  CGameMap();
  virtual ~CGameMap();
  IGameElement* m_gameObj[MAPROW * MAPCOL + NPLAYER + NGHOST];
};

// 创建单例类的类
CREATE_SINGLE_OBJ(CGameMap);

#endif // CGAMEMAPHEADER