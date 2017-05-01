#ifndef IGAMEELEMENTHEADER
#define IGAMEELEMENTHEADER
#pragma once
#include "pacMan.h"
#include "preStatement.h"

class IGameElement
{
public:
  virtual ~IGameElement() = 0;

  /* 获取对象坐标 */
  virtual int& operator[](int nIndex) = 0;

  /* 与其他对象比较碰撞等级 */
  virtual const int operator==(IGameElement& obj) = 0;

  /* 获取坐标对象 */
  virtual CPostion& getPos() = 0;

  /* 获取当前对象类型 */
  virtual const int getType() = 0;

  /* 改变类型 */
  virtual void changeType(int nType) = 0;

  /* 移动 */
  virtual int move() = 0;

  /* 改变方向 */
  virtual int changeAction(int nAct, int nMode = 1) = 0;

  /* 碰撞检测 */
  virtual const int isCrash(int nMode = 0) = 0;

  /* 撞到比自己等级高的 */
  virtual void beHit() = 0;

  /* 撞到比自己等级低的 */
  virtual void hitAnthor() = 0;

  /* 创建自身 */
  virtual IGameElement* creatSelf(int nRow, int nCol) = 0;
};

#endif // IGAMEELEMENTHEADER
