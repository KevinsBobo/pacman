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
  static void toFear();

private:
  int m_nWhatGhost;
};

