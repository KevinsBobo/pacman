#ifndef CGAMEMAPHEADER
#define CGAMEMAPHEADER
#pragma once
#include "pacMan.h"

class CGameMap
{
public:
  CGameMap();
  virtual ~CGameMap();

  void show(echoMapElement echoFun);

private:
  IGameElement* m_gameObj[MAPROW * MAPCOL + NPLAYER + NGHOST];
};

#endif // CGAMEMAPHEADER