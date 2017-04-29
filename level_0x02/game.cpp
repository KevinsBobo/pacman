#include "preStatement.h"
#include "game.h"

/* 默认变量 */
const clock_t g_nInitGhoSpead = 500;
const clock_t g_nInitPlayerSpead = 500;
const int g_nMapRow = 31;
const int g_nMapCol = 28;
const int g_nPlayer = 1;
const int g_nGhost = 4;

CGameMap* g_gameMap = NULL;

const int g_nFirstGhoRow = 14;
const int g_nFirstGhoCol = 12;

const int g_nPlayerRow = 23;
const int g_nPlayerCol = 13;

// 玩家已得分数
int g_nAddScore = 0;
// 玩家吃鬼分数
int g_nPlayerEatGhostScore = 200;
// 玩家吃鬼加分倍率
const float g_fMagScore = 1.5;
// 玩家被吃标志
int g_isBeEat = 0;
// 吃掉一只鬼
int g_nGhostBeEat = 0;
// 超级豆被吃标志，吃一个加1
int g_nSuperPeanBeEat = 0;
// 吃超级豆分数
const int g_nSuperPeanBeEatScore = 1;
// 吃豆子分数
const int g_nPeanBeEatScore = 1;
// 鬼恐惧时间
const clock_t g_nGhostFearTime = 4000;

CGame::CGame()
{
}


CGame::~CGame()
{
}
