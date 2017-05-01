#ifndef CGAMEUIHEADER
#define CGAMEUIHEADER
#pragma once
#include "pacMan.h"

class CGameUI
{
public:
  enum gameColor
  {
    colBlack = 0,
    colBlue,
    colGreen,
    colLightBlue,
    colRed,
    colPurple,
    colYellow,
    colWhite,
    colGray,
    colThinBlue,
    colThinGreen,
    colThinLightGreen,
    colThinRed,
    colThinPurple,
    colThinYellow,
    colLightWhite
  };

  // 单例模式创建函数
  SINGLE_INSTANCE_STAT(CGameUI);

  void echoMap(int nRow , int nCol , int nType);

  // 输出游戏信息
  void echoGameInfo(int nScore, int nGhostLevel, int nPlayerLife);

  // 在消息区域显示消息
  void echoGameMessage(char* szBuff);

  void echoMapByPrintf(int nRow , int nCol , int nType);

  void echoMapByApi(int nRow , int nCol , int nType);

  /*******************************
  函数功能：打印字符到控制台制定位置
  High: 高度X行，行数
  Wide: 宽度Y列，列数
  pszChar: 打印的字符
  wArr: 打印字符的属性
  *******************************/
  void writeChar(int High , int Wide , char* pszChar , WORD wArr);
  
  /*********************************
  函数功能: 设置窗口信息
  *pszWindewTitle: 窗口名称
  nY: 窗口高度，行数
  nX: 窗口宽度，列数
  成功返回值: true
  *********************************/
  bool setWindowSize(char *pszWindowTitle , int nY , int nX);
private:
  CGameUI();
  virtual ~CGameUI();

  char* m_elementStr[ CGame::itemPlayer + 1 ];
  int m_elementColor[ CGame::itemPlayer + 1 ];
};

// 创建单例类的类
CREATE_SINGLE_OBJ(CGameUI);

#endif // CGAMEUIHEADER