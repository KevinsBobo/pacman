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
  //TODO: insert return statement here
  return m_postion[nIndex];
}

// 与其他对象比较碰撞等级
const int CGameElement::operator==(IGameElement& obj)
{

  return 0;
}


// 获取类型
const int CGameElement::getType()
{
  return m_nType;
}


// 移动
int CGameElement::move()
{
  return 0;
}

// 改变方向
int CGameElement::changeAction(int nAct)
{
  return 0;
}

// 碰撞检测
const int CGameElement::isCrash()
{
  return 0;
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