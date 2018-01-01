#ifndef __GLOBF__H
#define __GLOBF__H


#include <windef.h>
#include <wingdi.h>
#include "struck.h"

void DrawRect(HDC hdc, Rect rect);
void Object_Show(HDC hdc, Point core, Point size, unsigned char *p, unsigned int rop = SRCCOPY);
void Init_TankImg(const char* szname, unsigned char* TankImg);
void Init_MapImg(const char* szname, unsigned char* MapImg, Point point = Point(20, 20));

void Empt();

#endif