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
  static const clock_t nRefreshTime = 200;
  static clock_t nowTime = 0;
  static char ch;

  m_mapObj->show(m_uiObj , &CGameUI::echoMap);
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

    if(checkStatus() == 1)
    {
      break;
    }

    for(int i = 0; i < g_nGhost + g_nPlayer; ++i)
    {
      m_moveObj[ i ]->move();
    }

    changeGhostAct();

    m_uiObj->echoGameInfo(m_playerObj->getScore() , g_nGhostLevel , m_playerObj->getlife());

    m_mapObj->show(m_uiObj , &CGameUI::echoMap);
  }
}

// 检查状态
int CGameCtrl::checkStatus()
{
  m_playerObj->addScore(g_nAddScore);
  g_nAddScore = 0;

  if(g_isBeEat == 1)
  {
    whenGhostEatPlayer();
  }
  else if(g_nGhostBeEat > 0)
  {
    whenPlayerEatGhost();
  }
  else if(g_nSuperPeanBeEat > 0)
  {
    whenPlayerEatSuperPean();
  }

  checkPlayerScore();

  if(m_playerObj->getlife() == 0)
  {
    return 1;
  }

  if(g_nEatPeanNum >= g_nPean)
  {
    whenAllPeanBeEat();
    return 1;
  }

  return 0;
}

// 当玩家吃掉超级豆
void CGameCtrl::whenPlayerEatSuperPean()
{
  static clock_t nowTime = 0;
  static const int nSuperPeanNum = 1;
  static int nTimeIsUpdate = 0;

  if(nTimeIsUpdate == 0)
  {
    g_nFearStartTime = clock();
    nTimeIsUpdate = 1;

    for(int i = 0; i < g_nGhost; ++i)
    {
        m_ghostObj[ i ]->toFear();
    }
  }

  if(g_nSuperPeanBeEat > nSuperPeanNum)
  {
    g_nFearStartTime += g_nGhostFearTime;
    --g_nSuperPeanBeEat;
  }

  nowTime = clock();
  if(nowTime - g_nGhostFearTime >= g_nFearStartTime)
  {
    nTimeIsUpdate = 0;
    g_nSuperPeanBeEat = 0;
    for(int i = 0; i < g_nGhost; ++i)
    {
      if(m_ghostObj[ i ]->getType() != CGame::itemGhoDie)
      {
        m_ghostObj[ i ]->changeType(CGame::itemGhoNormal);
      }
    }
  }
}

// 当玩家碰撞恐惧时的鬼
void CGameCtrl::whenPlayerEatGhost()
{
  static int nScore = PLAYEREATGHOSTSCORE;;
  char szBuff[ 0x20 ] = { 0 };
  sprintf_s(szBuff , 0x20 , "玩家得分：%d" , nScore);
  m_uiObj->echoGameMessage(szBuff);

  g_nFearStartTime += 1200;

  nScore = (int)(nScore * g_fMagScore);
  
  g_nGhostBeEat -= 1;
}

// 当玩家碰撞正常鬼
void CGameCtrl::whenGhostEatPlayer()
{
  m_uiObj->echoGameMessage("吃豆人被抓啦！");

  g_isBeEat = 0;
  g_nGhostBeEat = 0;
  g_nSuperPeanBeEat = 0;

  // 玩家、鬼回位
  for(int i = 0; i < g_nGhost + g_nPlayer; ++i)
  {
    ((CMoveObj*)m_moveObj[ i ])->backPos();
  }
}

// 当玩家吃完所有豆子
void CGameCtrl::whenAllPeanBeEat()
{
  m_uiObj->echoGameMessage("吃豆人吃饱啦！");
  // todo ..
}

// 检查玩家分数、升级鬼
void CGameCtrl::checkPlayerScore()
{
  static int nSpead = g_nInitGhoSpead;
  if(m_playerObj->getScore() > 100 * g_nGhostLevel && g_nGhostLevel < 4)
  {
    nSpead -= 50;
    g_nGhostLevel += 1;
    for(int i = 0; i < g_nGhost; ++i)
    {
      m_ghostObj[ i ]->setSpead(nSpead);
    }
  }
}

// 改变鬼的方向
void CGameCtrl::changeGhostAct()
{
  static clock_t nPreTime = 0;
  clock_t nowTime = clock();
  if(nowTime - m_ghostObj[0]->getSpead() < nPreTime)
  {
    return;
  }
  nPreTime = nowTime;
  int nAct = 0;
  CPostion dstPos;
  // 地图的四个角落，用于四只鬼的逃亡模式和黄鬼的巡逻角落
  static CPostion mapFourNook[ 4 ];
  mapFourNook[ 0 ].set(5 , 6);
  mapFourNook[ 1 ].set(5, g_nMapCol - 7);
  mapFourNook[ 2 ].set(g_nMapRow - 5 , 6);
  mapFourNook[ 3 ].set(g_nMapRow - 5 , g_nMapCol - 7);
  static int ghostInNook[ 4 ] = { 0 };

  for(int i = 0; i < g_nGhost; ++i)
  {
    // 设置每个鬼的追击目标
    if(m_ghostObj[i]->getType() == CGame::itemGhoRed)
    {
      // 红鬼追击玩家
      nAct = findAction(m_ghostObj[i]->getPos(), m_playerObj->getPos(), m_ghostObj[i]->getAction());
    }
    else if(m_ghostObj[i]->getType() == CGame::itemGhoYell)
    {
      // 黄鬼追击玩家
      // 先判断玩家是否进入其追踪范围（这只鬼原则是离玩家远了就追玩家，近了就不追）
      // 算对角线
      dstPos = m_ghostObj[ i ]->getPos() - m_playerObj->getPos();
      // dstPos.amend();
      if(dstPos[ CGame::posRow ] * dstPos[CGame::posRow] + dstPos[CGame::posCol] * dstPos[CGame::posCol] > 128)
      {
        // 追踪玩家
        nAct = findAction(m_ghostObj[i]->getPos(), m_playerObj->getPos(), m_ghostObj[i]->getAction()); 
      }
      else
      {
        // 自己干自己的事情
        nAct = findAction(m_ghostObj[i]->getPos(), mapFourNook[0], m_ghostObj[i]->getAction()); 
      }
    }
    else if(m_ghostObj[ i ]->getType() == CGame::itemGhoPink)
    {
      // 粉鬼追踪玩家
      // 获取玩家朝向的第4个坐标，左边2个坐标
      dstPos = m_playerObj->getPos();
      for(int j = 0; j < 4; ++j)
      {
        dstPos = dstPos.getActionPostion(m_playerObj->getAction());
      }
      dstPos = dstPos.getActionPostion(CGame::actLeft);
      dstPos = dstPos.getActionPostion(CGame::actLeft);
      nAct = findAction(m_ghostObj[i]->getPos(), dstPos, m_ghostObj[i]->getAction());
    }
    else if(m_ghostObj[i]->getType() == CGame::itemGhoBlue)
    {
      // 蓝鬼追踪玩家
      // 获取玩家朝向的第2个坐标
      dstPos = m_playerObj->getPos();
      for(int j = 0; j < 2; ++j)
      {
        dstPos = dstPos.getActionPostion(m_playerObj->getAction());
      }
      // 获取红鬼和玩家朝向的前两格的坐标差
      dstPos = m_ghostObj[ CGame::itemGhoRed - CGame::itemGhoRed ]->getPos() - dstPos;
      // 将该坐标差翻倍
      dstPos = dstPos * 2;
      // 定位到红鬼和玩家朝向的前两格的连线的2背延长线的坐标
      dstPos = m_ghostObj[ CGame::itemGhoRed - CGame::itemGhoRed ]->getPos() + dstPos;

      nAct = findAction(m_ghostObj[i]->getPos(), dstPos, m_ghostObj[i]->getAction());
    }
    // 鬼死亡时，回家
    else if(m_ghostObj[ i ]->getType() == CGame::itemGhoDie)
    {
      // 将四只鬼目标定在鬼家中不同位置
      dstPos.set(g_nFirstGhoRow + (i % 2) , g_nFirstGhoCol + ((i - 1) / 2) * 4);
      nAct = findAction(m_ghostObj[i]->getPos(), dstPos, m_ghostObj[i]->getAction());
    }
    // 鬼恐惧状态时，到各自的角落去
    else if(m_ghostObj[ i ]->getType() == CGame::itemGhoFear)
    {
      // 黄鬼、红鬼，回家
      if(m_ghostObj[ i ]->getWhatGhost() == CGame::itemGhoYell || m_ghostObj[i]->getWhatGhost() == CGame::itemGhoRed)
      {
        dstPos.set(g_nFirstGhoRow + 1, g_nFirstGhoCol + 1);
        nAct = findAction(m_ghostObj[i]->getPos(), dstPos, m_ghostObj[i]->getAction());
      }
      // 蓝鬼、粉鬼到自己的角落去
      else
      {
        // 根据位置状态选择目标角落
        if(ghostInNook[ m_ghostObj[ i ]->getWhatGhost() - CGame::itemGhoRed ] == 0)
        {
          dstPos = mapFourNook[ m_ghostObj[ i ]->getWhatGhost() - CGame::itemGhoRed ];
        }
        else
        {
          dstPos = mapFourNook[ m_ghostObj[ i ]->getWhatGhost() - CGame::itemGhoRed - 1 ];
        }
        // 当到达一个角落
        if(dstPos == m_ghostObj[ i ]->getPos())
        {
          // 切换位置状态
          ghostInNook[ m_ghostObj[ i ]->getWhatGhost() - CGame::itemGhoRed ] =
            (ghostInNook[ m_ghostObj[ i ]->getWhatGhost() - CGame::itemGhoRed ] == 0) ?
            1 : 0;
        }
        
        nAct = findAction(m_ghostObj[i]->getPos(), dstPos, m_ghostObj[i]->getAction());
      }
    }
    m_ghostObj[ i ]->changeAction(nAct);
  }
}

// 寻路算法
int CGameCtrl::findAction(CPostion srcPos , CPostion dstPos, int nAct)
{
  /********************************************
  * 整个算法的目的就是为了知道下一步该向那个方向走
  * 所以所有的操作都围绕保存正确的方向为主
  * 因此也不需要保存走过的路径
  *********************************************/
  
  // 判断传入坐标是否正确
  while(true)
  {
    // 将坐标数据合法化
    dstPos.amend();
    // 检查该坐标是否是墙
    if(((*g_gameMap)[ dstPos[ CGame::posRow ] ][ dstPos[ CGame::posCol ] ])->getType() != CGame::itemWall)
    {
      break;
    }
    // 如果是墙就将坐标向其方向移动一个后再判断
    dstPos = dstPos.getActionPostion(CGame::actDown);
  }

  // 地图数组，用于保存走过的路
  int nPassPostion[ MAPROW ][ MAPCOL ] = { 0 };

  // 寻路状态结点结构体，这里不放CPostion类型了，影响效率
  typedef struct FindState
  {
    int nRow;
    int nCol;
    enum CGame::gameAction myAction;
    enum CGame::gameAction firstAction;
  } FindState;

  // 两个状态结点数组，用于保存寻址信息
  FindState* nowStateArr = new FindState[ 300 ];
  FindState* preStateArr = new FindState[ 300 ];
  FindState* pTempArr;
  // 两个数组下标
  int nNowArrCur = -1;
  int nPreArrCur = -1;

  // 创建一只鬼用来模拟路径
  CGhost moveGho(srcPos[ CGame::posRow ] , srcPos[ CGame::posCol ]);
  moveGho.changeType(CGame::itemGhoTremble);
  moveGho.setSpead(0);

  // 初始数组信息
  ++nPreArrCur;
  preStateArr[ nPreArrCur ].nRow = srcPos[ CGame::posRow ];
  preStateArr[ nPreArrCur ].nCol = srcPos[ CGame::posCol ];
  preStateArr[ nPreArrCur ].myAction = CGame::actUp;
  preStateArr[ nPreArrCur ].firstAction = CGame::actUp;
  nPassPostion[ srcPos[ CGame::posRow ] ][ srcPos[ CGame::posCol ] ] = 1;

  int nFindNum = 0;

  CPostion tempPos;
  int nNewRow;
  int nNewCol;
  int nRet = 0;
  while(true)
  {
    // 判断是否到达目标坐标点
    for(int i = 0; i <= nPreArrCur; ++i)
    {
      tempPos.set(preStateArr[ i ].nRow , preStateArr[ i ].nCol);
      if((tempPos == dstPos) == 1)
      {
        nRet = preStateArr[ i ].firstAction;
        delete nowStateArr;
        delete preStateArr;
        // 再模拟走一步，看是否被动态元素挡住去路 // 现在是鬼和鬼不会碰撞，所以就不需要这一步了
        // moveGho.getPos() = srcPos;
        // if(moveGho.changeAction(nRet) != 0)
        // {
        //   // 下一步被动态元素挡住去路，返回相反方向
        //   nRet = (nAct <= 1) ? (nAct + 1) % 2  : (nAct - 3 + 1) % 2 + 3;
        // }
        return nRet;
      }
    }

    ++nFindNum;
    // 从当前状态继续寻找
    for(int i = 0; i <= nPreArrCur && nPreArrCur >= 0; ++i)
    {
      // 获取状态坐标值
      tempPos.set(preStateArr[ i ].nRow , preStateArr[ i ].nCol);
      
      // 遍历四个方向
      for(int j = CGame::actUp; j <= CGame::actRight; ++j)
      {
        // 更新鬼的坐标信息，准备模拟
        moveGho.getPos() = tempPos;

        // 判断是否被静态元素挡住路
        if(moveGho.changeAction(j, 2) != 0)
        {
          // 不能朝该方向移动
          continue;
        }

        // 可以移动，更新坐标信息
        moveGho.getPos() = tempPos.getActionPostion(j);
        
        // 获取移动后的新坐标
        nNewRow = moveGho.getPos()[ CGame::posRow ];
        nNewCol = moveGho.getPos()[ CGame::posCol ];

        // 非首次
        if(nFindNum > 1 && nPassPostion[ nNewRow ][ nNewCol ] == 0)
        {
          ++nNowArrCur;
          nowStateArr[ nNowArrCur ].nRow = nNewRow;
          nowStateArr[ nNowArrCur ].nCol = nNewCol;
          nowStateArr[ nNowArrCur ].myAction = (enum CGame::gameAction)j;
          // 关键在这一步，保存前一状态中记录的初始方向
          nowStateArr[ nNowArrCur ].firstAction = preStateArr[i].firstAction;
          nPassPostion[ nNewRow ][ nNewCol ] = nFindNum;

        }
        // 首次
        else if(nFindNum == 1 && nPassPostion[ nNewRow ][ nNewCol ] == 0)
        {
          ++nNowArrCur;
          nowStateArr[ nNowArrCur ].nRow = nNewRow;
          nowStateArr[ nNowArrCur ].nCol = nNewCol;
          nowStateArr[ nNowArrCur ].myAction = (enum CGame::gameAction)j;
          nowStateArr[ nNowArrCur ].firstAction = (enum CGame::gameAction)j;
          nPassPostion[ nNewRow ][ nNewCol ] = nFindNum;
        }
      }
    }

    // 交换寻址状态数组指针所指空间，从而保存当前状态，丢弃之前的状态
    pTempArr = preStateArr;
    preStateArr = nowStateArr;
    nowStateArr = pTempArr;
    // 重置数组下标
    nPreArrCur = nNowArrCur;
    nNowArrCur = -1;
  }
}

// 创建单例类的类
CREATE_SINGLE_OBJ_REALIZE(CGameCtrl);