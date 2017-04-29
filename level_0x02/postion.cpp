#include "postion.h"


CPostion::CPostion()
  : m_nRow(0) , m_nCol(0)
{
}

CPostion::CPostion(int nRow , int nCol)
  : m_nRow(nRow) , m_nCol(nCol)
{

}

CPostion::~CPostion()
{
}


// 初始化地图
void CPostion::initMap()
{
}


// 获取对应横纵坐标
int& CPostion::operator[](int nIndex)
{
  return (nIndex == CGame::posRow) ? m_nRow : m_nCol;
}


// 坐标赋值
void CPostion::operator=(CPostion& obj)
{
}


// 判断坐标是否相等
int CPostion::operator==(CPostion& obj)
{
  return 0;
}


// 设置坐标
void CPostion::set(int nRow , int nCol)
{
}


// 获取这个方向下个坐标
CPostion& CPostion::getActionPostion(int nAction)
{
  //TODO: insert return statement here
  return *this;
}


// 根据方向修改坐标
void CPostion::changePostion(int nAction)
{
}
