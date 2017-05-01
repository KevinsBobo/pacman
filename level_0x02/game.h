#ifndef CGAMEHEADER
#define CGAMEHEADER
#pragma once
#include <ctime>
#include "preStatement.h"

/* 默认变量 */
extern const clock_t g_nInitGhoSpead;
extern const clock_t g_nInitPlayerSpead;
extern const int g_nMapRow;
extern const int g_nMapCol;
extern const int g_nPlayer;
extern const int g_nGhost;
extern const int g_nPean;
extern int g_nPlayerlife;

extern CGameMap* g_gameMap;

extern const int g_nFirstGhoRow;
extern const int g_nFirstGhoCol;

extern const int g_nPlayerRow;
extern const int g_nPlayerCol;

// 玩家已得分数
extern int g_nAddScore;
// 玩家吃鬼分数
extern int g_nPlayerEatGhostScore;
// 玩家吃鬼加分倍率
extern const float g_fMagScore;
// 玩家被吃标志
extern int g_isBeEat;
// 吃掉一只鬼
extern int g_nGhostBeEat;
// 玩家吃掉豆子的数量（包括超级豆），最多300
extern int g_nEatPeanNum;
// 超级豆被吃标志，吃一个加1
extern int g_nSuperPeanBeEat;
// 吃超级豆分数
extern const int g_nSuperPeanBeEatScore;
// 吃豆子分数
extern const int g_nPeanBeEatScore;
// 鬼恐惧时间
extern const clock_t g_nGhostFearTime;
// 鬼开始恐惧时间
extern clock_t g_nFearStartTime;
// 鬼等级
extern int g_nGhostLevel;

#define MAPROW  31
#define MAPCOL  28
#define NPLAYER 1
#define NGHOST  4
#define NCLASS  14 // 游戏元素数量
#define PLAYEREATGHOSTSCORE 50

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
    itemGhoTremble,
    itemGhoFear,
    itemGhoDie,
    itemPlayer
  };

  CGame();
  ~CGame();
};

#endif // CGAMEHEADER