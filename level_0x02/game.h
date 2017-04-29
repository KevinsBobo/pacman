#ifndef CGAMEHEADER
#define CGAMEHEADER
#pragma once
#include <ctime>

/* 默认变量 */
extern const clock_t g_nInitGhoSpead;
extern const clock_t g_nInitPlayerSpead;
extern const int g_nMapRow;
extern const int g_nMapCol;
extern const int g_nPlayer;
extern const int g_nGhost;

#define MAPROW  31
#define MAPCOL  28
#define NPLAYER 1
#define NGHOST  4
#define NCLASS  14 // 游戏元素数量

class CGame
{
public:
  enum gameAction
  {
    actUp = 0,
    actDown,
    actLeft,
    actRight
  };
  enum gamePostion
  {
    posRow = 0,
    posCol
  };
  enum gameCrash
  {
    craBeHit = -1,
    craNo    = 0,
    craHitAn,
    craPass
  };
  enum gameElement
  {
    itemPean = 0,
    itemWall,
    itemSurperPean,
    itemRoad,
    itemGhoHome,
    itemGhoNormal,
    itemGhoRed,
    itemGhoYell,
    itemGhoBlue,
    itemGhoPink,
    itemGhoFear,
    itemGhoTremble,
    itemGhoDie,
    itemPlayer
  };

  CGame();
  ~CGame();
};

#endif // CGAMEHEADER