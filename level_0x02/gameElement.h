#ifndef CGAMEELEMENTHEADER
#define CGAMEELEMENTHEADER
#pragma once

#include "pacMan.h"
#include "iGameElement.h"

class CGameElement :
  public IGameElement
{
public:
  CGameElement();
  CGameElement(int nRow , int nCol);
  virtual ~CGameElement();
  // 获取对象坐标
  virtual int& operator[](int nIndex);
  // 与其他对象比较碰撞等级
  virtual const int operator==(IGameElement& obj);
  // 获取坐标对象
  virtual CPostion& getPos();
  // 获取类型
  virtual const int getType();
  // 改变类型
  virtual void changeType(int nType);
  // 移动
  virtual int move();
  // 改变方向
  virtual int changeAction(int nAct);
  // 碰撞检测
  virtual const int isCrash(int nMode = 0);
  // 撞到比自己碰撞等级高的
  virtual void beHit();
  // 撞到比自己碰撞等级低的
  virtual void hitAnthor();
  // 创建自身
  virtual IGameElement* creatSelf(int nRow, int nCol);

protected:
  CPostion m_postion;
  int m_nType;
  int m_nAction;
};

#endif // CGAMEELEMENTHEADER