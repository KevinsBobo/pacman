#include "gameUI.h"

char* g_elementStr[ CGame::itemPlayer + 1 ] =
{"·", "■", "Θ", "  ", "  ", "★", "★", "★", "★", "★", "★", "★", "№", "●"};
int g_elementColor[ CGame::itemPlayer + 1 ] =
{
  CGameUI::colWhite * 16 + CGameUI::colYellow ,
  CGameUI::colWhite * 16 + CGameUI::colBlue ,
  CGameUI::colWhite * 16 + CGameUI::colThinYellow ,
  CGameUI::colWhite * 16 + CGameUI::colGray ,
  CGameUI::colWhite * 16 + CGameUI::colGray ,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colThinRed   ,
  CGameUI::colWhite * 16 + CGameUI::colYellow,
  CGameUI::colWhite * 16 + CGameUI::colLightBlue  ,
  CGameUI::colWhite * 16 + CGameUI::colThinPurple,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colBlack ,
  CGameUI::colWhite * 16 + CGameUI::colThinYellow
};

int g_wallMap[ MAPROW ][ MAPCOL ] =
{
  2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
  1,9,9,9,9,9,9,9,9,9,9,9,9,2,3,9,9,9,9,9,9,9,9,9,9,9,9,1,
  1,9,2,0,0,3,9,2,0,0,0,3,9,1,1,9,2,0,0,0,3,9,2,0,0,3,9,1,
  1,9,1,6,6,1,9,1,6,6,6,1,9,1,1,9,1,6,6,6,1,9,1,6,6,1,9,1,
  1,9,4,0,0,5,9,4,0,0,0,5,9,4,5,9,4,0,0,0,5,9,4,0,0,5,9,1,
  1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,
  1,9,2,0,0,3,9,2,3,9,2,0,0,0,0,0,0,3,9,2,3,9,2,0,0,3,9,1,
  1,9,4,0,0,5,9,1,1,9,4,0,0,3,2,0,0,5,9,1,1,9,4,0,0,5,9,1,
  1,9,9,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,9,9,1,
  4,0,0,0,0,3,9,1,4,0,0,3,9,1,1,9,2,0,0,5,1,9,2,0,0,0,0,5,
  1,6,6,6,6,1,9,1,2,0,0,5,9,4,5,9,4,0,0,3,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,9,9,9,9,9,9,9,9,9,1,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,2,0,0,8,8,0,0,3,9,1,1,9,1,6,6,6,6,1,
  4,0,0,0,0,5,9,4,5,9,1,7,7,7,7,7,7,1,9,4,5,9,4,0,0,0,0,5,
  9,9,9,9,9,9,9,9,9,9,1,7,7,7,7,7,7,1,9,9,9,9,9,9,9,9,9,9,
  2,0,0,0,0,3,9,2,3,9,1,7,7,7,7,7,7,1,9,2,3,9,2,0,0,0,0,3,
  1,6,6,6,6,1,9,1,1,9,4,0,0,0,0,0,0,5,9,1,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,9,9,9,9,9,9,9,9,9,1,1,9,1,6,6,6,6,1,
  1,6,6,6,6,1,9,1,1,9,2,0,0,0,0,0,0,3,9,1,1,9,1,6,6,6,6,1,
  2,0,0,0,0,5,9,4,5,9,4,0,0,3,2,0,0,5,9,4,5,9,4,0,0,0,0,3,
  1,9,9,9,9,9,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,9,9,9,9,9,1,
  1,9,2,0,0,3,9,2,0,0,0,3,9,1,1,9,2,0,0,0,3,9,2,0,0,3,9,1,
  1,9,4,0,3,1,9,4,0,0,0,5,9,4,5,9,4,0,0,0,5,9,1,2,0,5,9,1,
  1,9,9,9,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,1,9,9,9,1,
  4,0,3,9,1,1,9,2,3,9,2,0,0,0,0,0,0,3,9,2,3,9,1,1,9,2,0,5,
  2,0,5,9,4,5,9,1,1,9,4,0,0,3,2,0,0,5,9,1,1,9,4,5,9,4,0,3,
  1,9,9,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,1,1,9,9,9,9,9,9,1,
  1,9,2,0,0,0,0,5,4,0,0,3,9,1,1,9,2,0,0,5,4,0,0,0,0,3,9,1,
  1,9,4,0,0,0,0,0,0,0,0,5,9,4,5,9,4,0,0,0,0,0,0,0,0,5,9,1,
  1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,
  4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5
};
// 0 橫墙 1 竖墙 2 左上角 3 右上角 4 左下角 5 右下角 6 内墙 7 鬼家中 8 鬼家门 9 豆子
// char* g_wall[ 9 ] = { "一", "│", "╭", "╮", "╰", "╯", "  ", "  ", "一"};
char* g_wall[ 9 ] = { "一", "│", "┏", "┓", "┗", "┛", "  ", "  ", "一"};

// 单例模式创建函数
SINGLE_INSTANCE(CGameUI);

CGameUI::CGameUI()
{
  setWindowSize("pacMan - KevinsBobo" , g_nMapRow , (g_nMapCol + 10) * 2);

  for(int nRow = 0; nRow < g_nMapRow; ++nRow)
  {
    for(int nCol = 0; nCol <= g_nMapCol + 10; ++nCol)
    {
      writeChar( nRow, nCol , "  " , CGameUI::colWhite * 16);
    }
  }

  memcpy_s(m_elementStr , sizeof(m_elementStr) , g_elementStr , sizeof(g_elementStr));
  memcpy_s(m_elementColor , sizeof(m_elementColor) , g_elementColor , sizeof(g_elementColor));
}


CGameUI::~CGameUI()
{
}

void CGameUI::echoMap(int nRow , int nCol , int nType)
{
  echoMapByApi(nRow , nCol , nType);
}

// 输出游戏信息
int echoInfoisStatic = 0;
void CGameUI::echoGameInfo(int nScore , int nGhostLevel , int nPlayerLife)
{
  static int nPreScore = nScore;
  static int nPreGhostLevel = nGhostLevel;
  static int nPrePlayerLife = nPlayerLife;
  char szBuff[ 0x20 ] = { 0 };

  int textColor = CGameUI::colWhite * 16 + CGameUI::colBlack;

  if(echoInfoisStatic == 0)
  {
    echoInfoisStatic = 1;

    sprintf_s(szBuff , 0x20 , "分数：%d    " , nScore);
    writeChar( 1, g_nMapCol + 1 , szBuff , textColor);
    sprintf_s(szBuff , 0x20 , "难度：%d    " , nGhostLevel);
    writeChar( 4, g_nMapCol + 1 , szBuff , textColor);
    sprintf_s(szBuff , 0x20 , "生命：%d    " , nPlayerLife);
    writeChar( g_nMapRow - 2, g_nMapCol + 1 , szBuff , textColor);
  }
  else
  {
    if(nScore != nPreScore)
    {
      nPreScore = nScore;
      sprintf_s(szBuff , 0x20 , "分数：%d    " , nScore);
      writeChar( 1, g_nMapCol + 1 , szBuff , textColor);
    }
    if(nGhostLevel != nPreGhostLevel)
    {
      nPreGhostLevel = nGhostLevel;
      sprintf_s(szBuff , 0x20 , "难度：%d    " , nGhostLevel);
      writeChar( 4, g_nMapCol + 1 , szBuff , textColor);
    }
    if(nPlayerLife != nPreGhostLevel)
    {
      nPrePlayerLife = nPlayerLife;
      sprintf_s(szBuff , 0x20 , "生命：%d    " , nPlayerLife);
      writeChar( g_nMapRow - 2, g_nMapCol + 1 , szBuff , textColor);
    }
  }
}

// 在消息区域显示消息
void CGameUI::echoGameMessage(char* szBuff, int nTime)
{
  int textColor = CGameUI::colWhite * 16 + CGameUI::colBlack;
  int nMassageBoxRow = 16;
  int nMassageBoxCol = g_nMapCol + 1;


  writeChar( nMassageBoxRow, nMassageBoxCol , szBuff , textColor);

  Sleep(nTime);

  writeChar( nMassageBoxRow, nMassageBoxCol , "                  " , textColor);

}

void CGameUI::echoMapByPrintf(int nRow , int nCol , int nType)
{
  printf("%s" , m_elementStr[ nType ]);
  if(nCol == g_nMapCol - 1)
  {
    printf("\n");
  }
}

int isInitRefash = 0;
void CGameUI::echoMapByApi(int nRow , int nCol , int nType)
{
  // 只刷新一次
  static int nMoveObjPreRow[ NPLAYER + NGHOST ] = { 0 };
  static int nMoveObjPreCol[ NPLAYER + NGHOST ] = { 0 };
  static int nMoveObjNowRow[ NPLAYER + NGHOST ] = { 0 };
  static int nMoveObjNowCol[ NPLAYER + NGHOST ] = { 0 };
  static int isMoved[ NPLAYER + NGHOST ] = { 0 };
  static int nTemp = 0;

  // 鬼恐惧状态结束前的闪烁
  static int* ghostColor = g_elementColor + CGame::itemGhoRed;
  static clock_t nowTime = 0;
  static clock_t flashTime = 400;
  static clock_t startTime = 2400;
  static clock_t passTime = 0;

  // 优化墙的显示
  char* pWallBuff = NULL;

  static int i = 0;
  // 刷新动、静态元素，只刷一次
  if(isInitRefash < g_nMapRow * g_nMapCol + g_nPlayer + g_nGhost)
  {
    if(nType == CGame::itemWall)
    {
      // 针对墙的特殊处理
      pWallBuff = g_wall[ g_wallMap[ nRow ][ nCol ] ];
      writeChar(nRow , nCol , pWallBuff , m_elementColor[ nType ]);
    }
    else if(nType == CGame::itemGhoHome)
    {
      // 针对鬼屋的特殊处理
      pWallBuff = g_wall[ g_wallMap[ nRow ][ nCol ] ];
      writeChar(nRow , nCol , pWallBuff , CGameUI::colWhite * 16 + CGameUI::colLightBlue);
    }
    else
    {
      // 其他元素
      writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
    }
    ++isInitRefash;
  }
  // 再刷新动态元素，只刷一次
  else if(isInitRefash < g_nMapRow * g_nMapCol + g_nGhost + g_nPlayer)
  {
    writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
    nMoveObjNowRow[ i ] = nRow;
    nMoveObjNowCol[ i ] = nCol;
    nMoveObjPreRow[ i ] = nRow;
    nMoveObjPreCol[ i ] = nCol;

    ++i;
    ++isInitRefash;
    if(i >= g_nGhost + g_nPlayer)
    {
      i = 0;
    }
  }
  // 只针对变化过的元素进行刷新
  else
  {
    // 动态元素
    if(nType >= CGame::itemGhoNormal && nType <= CGame::itemPlayer)
    {
      // 如果移动了就记录他之前的坐标和现在的坐标
      if(nMoveObjNowRow[ i ] != nRow || nMoveObjNowCol[ i ] != nCol)
      {
        nTemp = nMoveObjPreRow[i];
        nMoveObjPreRow[i] = nMoveObjNowRow[i];
        nMoveObjNowRow[i] = nTemp;
        
        nTemp = nMoveObjPreCol[i];
        nMoveObjPreCol[i] = nMoveObjNowCol[i];
        nMoveObjNowCol[i] = nTemp;
        
        nMoveObjNowRow[ i ] = nRow;
        nMoveObjNowCol[ i ] = nCol;
        isMoved[ i ] = 1;

        // 先刷一次，防止卡顿
        writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
      }
      // 如果没有移动，就输出该元素
      // 也就是会动的元素只有在移动后的一刹那不会刷新，
      // 进入下一刹那它就是没有移动过的元素，就不断刷新它到屏幕
      else
      {
        // 针对鬼快要结束恐惧状态前的做闪烁处理
        if(nType == CGame::itemGhoFear )
        {
          nowTime = clock();
          passTime = nowTime - g_nFearStartTime - g_nGhostFearTime + startTime;
          if(passTime >= 0 && (passTime % (flashTime * 2)) <= flashTime)
          {
            writeChar(nRow , nCol , m_elementStr[ nType ] , ghostColor[i]);
          }
          else
          {
            writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
          }
        }
        // 其他元素正常刷
        else
        {
          writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
        }
        isMoved[ i ] = 0;
      }

      // 计数
      ++i;
      if(i >= g_nGhost + g_nPlayer)
      {
        i = 0;
      }
    }
    // 静态元素
    else
    {
      for(int j = 0; j < g_nGhost + g_nPlayer; ++j)
      {
        // 检查该是否为动态元素是否移动，如过移动则刷新其移动前的位置元有的静态元素
        if(isMoved[ j ] == 1 && nRow == nMoveObjPreRow[ j ] && nCol == nMoveObjPreCol[ j ])
        {
          // 针对鬼家做的处理
          if(nType == CGame::itemGhoHome)
          {
            pWallBuff = g_wall[ g_wallMap[ nRow ][ nCol ] ];
            writeChar(nRow , nCol , pWallBuff , CGameUI::colWhite * 16 + CGameUI::colLightBlue);
          }
          // 其他元素正常刷
          else
          {
            writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
          }
          isMoved[ j ] = 0;
          break;
        }
      }
    }
  }

}

void CGameUI::writeChar(int High , int Wide , char* pszChar , WORD wArr){
	CONSOLE_CURSOR_INFO cii;
	cii.dwSize = 1;
	cii.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &cii);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , loc);
	printf(pszChar);
}

bool CGameUI::setWindowSize(char *pszWindowTitle  , int nY, int nX){
	// Title
	SetConsoleTitleA(pszWindowTitle);
	HANDLE hStdin , hStdOut;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// get max console window size
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BufferSize = { pos.X + 1 , pos.Y + 1 };
	// set console buffer size
	if(!SetConsoleScreenBufferSize(hStdOut , BufferSize)){
		// set console buffer size false
		printf("buffer err(%d,%d)%d\n" , BufferSize.X , BufferSize.Y , GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0 , 0 , nX , nY };
	if(!SetConsoleWindowInfo(hStdOut , true , &srctWindow)){
		// set console window size false
		printf("size err %d\n" , GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1 , nY + 1 };
	// set console buffer size
	if(!SetConsoleScreenBufferSize(hStdOut , Buffer)){
		// set console buffer size false
		printf("buffer err(%d, %d)%d\n" , BufferSize.X , BufferSize.Y , GetLastError());
		return false;
	}
	return true;
}

// 创建单例类的类
CREATE_SINGLE_OBJ_REALIZE(CGameUI);