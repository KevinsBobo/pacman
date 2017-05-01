#ifndef CMOVEOBJHEADER
#define CMOVEOBJHEADER
#pragma once
#include "pacMan.h"
#include "gameElement.h"

class CMoveObj :
  public CGameElement
{
public:
  CMoveObj();
  CMoveObj(int nRow , int nCol);
  virtual ~CMoveObj();
  // 更新时间，并返回时间是否大于对象速度
  virtual int updateClock();
  // 移动
  virtual int move();
  // 设置速度
  virtual void setSpead(int nSpead);
  // 获取速度
  virtual clock_t getSpead();
  // 回位
  virtual void backPos();
  // 获取方向
  virtual int getAction();

protected:
  clock_t m_nSpead;
  clock_t m_nPreMoveClock;
};

#endif // CMOVEOBJHEADER