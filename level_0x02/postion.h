#ifndef POSTIONHEADER
#define POSTIONHEADER
#pragma once
#include "game.h"

class CPostion
{
public:
  CPostion();
  CPostion(int nRow , int nCol);
  CPostion(CPostion& obj);
  ~CPostion();
  // 获取对应横纵坐标
  int& operator[](int nIndex);
  // 坐标赋值
  void operator=(CPostion& obj);
  // 判断坐标是否相等
  int operator==(CPostion& obj);
  // 设置坐标
  void set(int nRow , int nCol);
  // 获取这个方向下个坐标
  CPostion getActionPostion(int nAction);
  // 根据方向修改坐标
  void changePostion(int nAction);

private:
  int m_nRow;
  int m_nCol;
};

#endif // POSTIONHEADER