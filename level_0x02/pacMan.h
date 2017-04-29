#pragma once

/* 系统头文件 */
#include <cstdio>
#include <ctime>
#include <cstring>
#include <windows.h>
#include <conio.h>

/* 项目头文件 */
#include "game.h"
#include "preStatement.h"
#include "single.h"
#include "funPtr.h"
#include "postion.h"
#include "gameUI.h"
#include "gameMap.h"
#include "gameCtrl.h"

#ifndef IGAMEELEMENTHEADER
#ifndef CGAMEELEMENTHEADER

#ifndef CSTATICOBJHEDAER
#include "road.h"
#include "pean.h"
#include "superPean.h"
#include "wall.h"
#include "ghoHome.h"
#endif // CSTATICOBJHEADER

#ifndef CMOVEOBJHEADER
#include "player.h"
#include "ghost.h"
#endif // CMOVEOBJHEADER

#endif // CGAMEELEMENTHEADER
#endif // IGAMEELEMENTHEADER