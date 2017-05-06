#include "gameElement.h"


CGameElement::CGameElement()
  : m_nAction(0) , m_postion() , m_nType(0)
{
}

CGameElement::CGameElement(int nRow , int nCol)
  : m_nAction(0) , m_postion(nRow , nCol) , m_nType(0)
{

}


CGameElement::~CGameElement()
{
}


// 获取对象坐标
int& CGameElement::operator[](int nIndex)
{
  return m_postion[nIndex];
}

// 与其他对象比较碰撞等级
const int CGameElement::operator==(IGameElement& obj)
{
  int nMyType = this->getType();

  // 撞墙
  if(obj.getType() == CGame::itemWall)
  {
    return CGame::craNo;
  }
  // 死鬼
  else if(nMyType == CGame::itemGhoDie)
  {
    return CGame::craPass;
  }
  // 撞路
  else if(obj.getType() == CGame::itemRoad)
  {
    return CGame::craPass;
  }
  // 撞豆子
  else if(obj.getType() == CGame::itemPean)
  {
    // 玩家撞豆
    if(nMyType == CGame::itemPlayer)
    {
      return CGame::craHitAn;
    }
    else
    {
      return CGame::craPass;
    }
  }
  // 撞鬼家
  else if(obj.getType() == CGame::itemGhoHome)
  {
    // 玩家撞鬼家
    if(nMyType == CGame::itemPlayer)
    {
      return CGame::craNo;
    }
    else
    {
      return CGame::craPass;
    }
  }
  // 撞超级豆
  else if(obj.getType() == CGame::itemSurperPean)
  {
    // 玩家撞超级豆
    if(nMyType == CGame::itemPlayer)
    {
      return CGame::craHitAn;
    }
    else
    {
      return CGame::craPass;
    }
  }
  // 撞死鬼
  else if (obj.getType() == CGame::itemGhoDie)
  {
    return CGame::craPass;
  }
  // 鬼撞鬼
  else if(nMyType >= CGame::itemGhoNormal && nMyType <= CGame::itemGhoDie &&
          obj.getType() >= CGame::itemGhoNormal && obj.getType() <= CGame::itemGhoDie)
  {
    // 鬼是可以相互穿越的
    // 恐惧状态的鬼可以相互穿过
    // if(nMyType == CGame::itemGhoFear || obj.getType() == CGame::itemGhoFear)
    // {
    //   return CGame::craPass;
    // }
    return CGame::craPass;
  }
  // 自己撞自己（基本上不可能，但要防止意外发生）
  else if(nMyType == obj.getType())
  {
    return CGame::craPass;
  }
  // 鬼撞玩家
  else if(obj.getType() == CGame::itemPlayer)
  {
    // 恐惧状态的鬼
    if(nMyType == CGame::itemGhoFear)
    {
      return CGame::craBeHit;
    }
    // 正常状态或颤抖状态的鬼
    else
    {
      return CGame::craHitAn;
    }
  }
  // 玩家撞鬼，当经过上面那么多判断还能到这里肯定就是玩家撞鬼了
  else if(nMyType == CGame::itemPlayer)
  {
    // 恐惧状态的鬼
    if(obj.getType() == CGame::itemGhoFear)
    {
      return CGame::craHitAn;
    }
    // 正常状态或颤抖状态的鬼
    else
    {
      return CGame::craBeHit;
    }
  }

  return CGame::craNo;
}

// 获取坐标对象
CPostion& CGameElement::getPos()
{
  return m_postion;
}

// 获取类型
const int CGameElement::getType()
{
  return m_nType;
}

// 改变类型
void CGameElement::changeType(int nType)
{
  m_nType = nType;
}

// 移动
int CGameElement::move()
{
  return 0;
}

// 改变方向
int CGameElement::changeAction(int nAct, int nMode)
{
  // if(m_nAction == nAct)
  // {
  //   return 0;
  // }
  int nPreAct = m_nAction;
  m_nAction = nAct;
  int nCrash = isCrash(nMode);
  if(nCrash == CGame::craNo)
  {
    m_nAction = nPreAct;
    return 1;
  }
  return 0;
}

// 碰撞检测
const int CGameElement::isCrash(int nMode)
{
  CPostion nextPos = m_postion.getActionPostion(m_nAction);
  IGameElement* nextObj = NULL;
  int nCrash = CGame::craPass;

  if(nMode != 2)
  {
    // 获取与动态对象碰撞结果
    nCrash = CGame::craPass;
    IGameElement** moveObj = g_gameMap->getMoveObj();
    nextObj = NULL;
    for(int i = 0; i < g_nGhost + g_nPlayer; ++i)
    {
      if(m_nType == moveObj[ i ]->getType() && m_postion == moveObj[i]->getPos())
      {
        continue;
      }

      if(nextPos == moveObj[ i ]->getPos())
      {
        nCrash = (*this == *moveObj[ i ]);
        nextObj = moveObj[ i ];
      }
    }

    if(nCrash == CGame::craNo)
    {
      return CGame::craNo;
    }
    else if(nMode == 0 && nCrash == CGame::craBeHit)
    {
      beHit();
      return CGame::craNo;
    }
    else if(nMode == 0 && nextObj != NULL && nCrash == CGame::craHitAn)
    {
      nextObj->beHit();
      return CGame::craNo;
    }

  }

  // 获取与静态对象碰撞结果
  nextObj = (*g_gameMap)[ nextPos[ CGame::posRow ] ][nextPos[CGame::posCol]];
  nCrash  = (*this == *nextObj);

  if(nCrash == CGame::craNo)
  {
    return CGame::craNo;
  }
  else if(nMode == 0 && nCrash == CGame::craHitAn)
  {
    nextObj->beHit();
  }
  return CGame::craPass;
}


// 撞到比自己碰撞等级高的
void CGameElement::beHit()
{

}


// 撞到比自己碰撞等级低的
void CGameElement::hitAnthor()
{

}

// 创建自身
IGameElement* CGameElement::creatSelf(int nRow, int nCol)
{
  return new CGameElement();
}