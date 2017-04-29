#include "gameUI.h"

char* g_elementStr[ CGame::itemPlayer + 1 ] =
{"·", "■", "●", "  ", "  ", "※", "※", "※", "※", "※", "※", "※", "№", "★"};
int g_elementColor[ CGame::itemPlayer + 1 ] =
{
  CGameUI::colWhite , CGameUI::colBlue  , CGameUI::colWhite , CGameUI::colBlack ,
  CGameUI::colBlack , CGameUI::colBlack , CGameUI::colRed   , CGameUI::colYellow,
  CGameUI::colBlue  , CGameUI::colThinRed, CGameUI::colGray , CGameUI::colGray ,
  CGameUI::colBlack , CGameUI::colYellow
};

// 单例模式创建函数
SINGLE_INSTANCE(CGameUI);

CGameUI::CGameUI()
{
  setWindowSize("pacMan - KevinsBobo" , g_nMapRow , g_nMapCol * 2);
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

void CGameUI::echoMapByPrintf(int nRow , int nCol , int nType)
{
  printf("%s" , m_elementStr[ nType ]);
  if(nCol == g_nMapCol - 1)
  {
    printf("\n");
  }
}

void CGameUI::echoMapByApi(int nRow , int nCol , int nType)
{
  writeChar(nRow , nCol , m_elementStr[ nType ] , m_elementColor[ nType ]);
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