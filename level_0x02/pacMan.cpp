#include "pacMan.h"

int main()
{

  CGetCGameCtrl gameCtrl;
  CGameCtrl* pGameObj = gameCtrl.get();

  pGameObj->gameLoop();


  return 0;
}