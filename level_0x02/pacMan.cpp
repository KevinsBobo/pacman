#include "pacMan.h"

int main()
{
  // CGameUI test;

  // test.echoMapByApi(5 , 10 , CGame::itemPlayer);

  // char* ch = "aa";
  // test.writeChar(5 , 12 , ch , CGameUI::colWhite);

  // CGameUI testUI;
  // CGameMap testMap;
  // testMap.show(testUI, &CGameUI::echoMapByApi);

  // CGetCGameUI test;
  // CGetCGameMap testMap;

  // CGameUI* testUI = test.get();
  // CGameMap* testMapObj = testMap.get();

  // testMapObj->show(testUI , &CGameUI::echoMap);

  CGetCGameCtrl test;
  CGameCtrl* testCtrl = test.get();

  testCtrl->gameLoop();


  return 0;
}