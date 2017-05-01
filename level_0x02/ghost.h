#pragma once
#include "pacMan.h"
#include "moveObj.h"

class CGhost :
  public CMoveObj
{
public:
  CGhost(int nRow, int nCol);
  virtual ~CGhost();
  virtual IGameElement* creatSelf(int nRow, int nCol);
  // 获取类型
  virtual const int getType();
  // 进入恐惧模式
  void toFear();

  void beHit();

  // 更新时间，并返回时间是否大于对象速度
  int updateClock();
  // 回位
  virtual void backPos();

  // 获取是什么颜色的鬼
  virtual int getWhatGhost();

private:
  int m_nWhatGhost;
};

