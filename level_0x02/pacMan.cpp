#include "pacMan.h"

int main()
{
  // CGameUI test;

  // test.echoMapByApi(5 , 10 , CGame::itemPlayer);

  // char* ch = "aa";
  // test.writeChar(5 , 12 , ch , CGameUI::colWhite);

  CGameMap testMap;
  testMap.show(&CGameUI::echoMapByApi);

  return 0;
}