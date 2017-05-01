#pragma once
#include "pacMan.h"
#include "moveObj.h"

class CPlayer :
  public CMoveObj
{
public:
  CPlayer(int nRow, int nCol);
  virtual ~CPlayer();
  virtual IGameElement* creatSelf(int nRow, int nCol);
  int getScore();
  void setScore(int nScore);
  void addScore(int nScore);
  int getlife();
  void setlife(int nlife);
  
  virtual void CPlayer::beHit();
  
  // 更新时间，并返回时间是否大于对象速度
  int updateClock();
  // 回位
  virtual void backPos();

private:
  int m_nScore;
  int m_nlife;
};

