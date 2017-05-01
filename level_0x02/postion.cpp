#include "postion.h"


CPostion::CPostion()
  : m_nRow(0) , m_nCol(0)
{
}

CPostion::CPostion(int nRow , int nCol)
  : m_nRow(nRow) , m_nCol(nCol)
{

}

CPostion::CPostion(CPostion& obj)
{
  m_nRow = obj.m_nRow;
  m_nCol = obj.m_nCol;
}

CPostion::~CPostion()
{
}

// 获取对应横纵坐标
int& CPostion::operator[](int nIndex)
{
  return (nIndex == CGame::posRow) ? m_nRow : m_nCol;
}


// 坐标赋值
CPostion& CPostion::operator=(CPostion& obj)
{
  m_nRow = obj.m_nRow;
  m_nCol = obj.m_nCol;
  return *this;
}


// 判断坐标是否相等
int CPostion::operator==(CPostion& obj)
{
  if(m_nRow == obj.m_nRow)
  {
    if(m_nCol == obj.m_nCol)
    {
      return 1;
    }
  }
  return 0;
}


// 将两个坐标相加（直接相加）
CPostion CPostion::operator+(CPostion& obj)
{
  CPostion tempPos = *this;
  tempPos.m_nRow += obj.m_nRow;
  tempPos.m_nCol += obj.m_nCol;
  tempPos.amend();
  return tempPos;
}

// 获取两个坐标差（横竖差坐标的差，可以是负值）
CPostion CPostion::operator-(CPostion& obj)
{
  CPostion tempPos = *this;
  tempPos.m_nRow -= obj.m_nRow;
  tempPos.m_nCol -= obj.m_nCol;
  return tempPos;
}

// 将坐标与数字相乘
CPostion CPostion::operator*(int nNum)
{
  CPostion tempPos = *this;
  tempPos.m_nRow *= nNum;
  tempPos.m_nCol *= nNum;
  return tempPos;
}

// 修正坐标（防止越界）
void CPostion::amend()
{
  m_nRow = (m_nRow + g_nMapRow) % g_nMapRow;
  m_nCol = (m_nCol + g_nMapCol) % g_nMapCol;
}

// 设置坐标
void CPostion::set(int nRow , int nCol)
{
  m_nRow = nRow;
  m_nCol = nCol;

  amend();
}


// 获取这个方向下个坐标
CPostion CPostion::getActionPostion(int nAction)
{
  CPostion nextPos = *this;
  // 更改元素Row位置
  nextPos[ CGame::posRow ] += ((2 & nAction) != 0) ? 0 :
    (((1 & nAction) == 0) ? -1 : 1);

  // 更改元素Col位置
  nextPos[ CGame::posCol ] += ((2 & nAction) == 0) ? 0 :
    (((1 & nAction) == 0) ? -1 : 1);

  nextPos[ CGame::posRow ] += (nextPos[ CGame::posRow ] < 0) ? g_nMapRow : 0;
  nextPos[ CGame::posCol ] += (nextPos[ CGame::posCol ] < 0) ? g_nMapCol : 0;

  nextPos.amend();

  return nextPos;
}

// 根据方向修改坐标
void CPostion::changePostion(int nAction)
{
  *this = getActionPostion(nAction);
}
