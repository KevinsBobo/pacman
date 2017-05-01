#include "preStatement.h"
#include "game.h"

/* 默认变量 */
const clock_t g_nInitGhoSpead = 350;
const clock_t g_nInitPlayerSpead = 200;
const int g_nMapRow = 31;
const int g_nMapCol = 28;
const int g_nPlayer = 1;
const int g_nGhost = 4;
const int g_nPean = 300;
int g_nPlayerlife = 3;

CGameMap* g_gameMap = NULL;

const int g_nFirstGhoRow = 14;
const int g_nFirstGhoCol = 12;

const int g_nPlayerRow = 23;
const int g_nPlayerCol = 13;

// 玩家已得分数
int g_nAddScore = 0;
// 玩家吃鬼分数
int g_nPlayerEatGhostScore = PLAYEREATGHOSTSCORE;
// 玩家吃鬼加分倍率
const float g_fMagScore = 1.5;
// 玩家被吃标志
int g_isBeEat = 0;
// 吃掉一只鬼
int g_nGhostBeEat = 0;
// 玩家吃掉豆子的数量（包括超级豆），最多300
int g_nEatPeanNum = 1;
// 超级豆被吃标志，吃一个加1
int g_nSuperPeanBeEat = 0;
// 吃超级豆分数
const int g_nSuperPeanBeEatScore = 1;
// 吃豆子分数
const int g_nPeanBeEatScore = 1;
// 鬼恐惧时间
const clock_t g_nGhostFearTime = 10000;
// 鬼开始恐惧时间
clock_t g_nFearStartTime = 0;
// 鬼等级
int g_nGhostLevel = 1;

CGame::CGame()
{
}


CGame::~CGame()
{
}
