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
  CPostion& operator=(CPostion& obj);
  // 将两个坐标相加（直接相加）
  CPostion operator+(CPostion& obj);
  // 获取两个坐标差（横竖差坐标的差，可以是负值）
  CPostion operator-(CPostion& obj);
  // 将坐标与数字相乘
  CPostion operator*(int nNum);
  // 判断坐标是否相等
  int operator==(CPostion& obj);
  // 修正坐标（防止越界）
  void amend();
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