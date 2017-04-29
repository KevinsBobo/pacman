#ifndef FUNPTRHEADER
#define FUNPTRHEADER
#pragma once

/* 函数指针 */

class IGameElement;
/* 子类创建自身的函数指针 */
typedef IGameElement* (IGameElement::*creatSelf)(int, int);

class CGameUI;
/* 控制台输出函数 */
typedef void (CGameUI::*echoMapElement)(int , int , int);

#endif // FUNPTRHEADER