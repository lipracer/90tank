#include "stdafx.h"
#include "GlobV.h"

Rect Window_Size = {0,0,Window_w,Window_h};
Rect Game_Region_Size = {Bound_w,Bound_h,Bound_w+Game_w,Bound_h+Game_h};
char tank_size = Tank_w;
BITMAPINFOHEADER bi = {};

HDC HDC_CompatibleDC = NULL;
HPEN oldPen, newPen;

unsigned char	*lpMyTankimg = NULL;
unsigned char	*lpETank1img = NULL;
unsigned char	*lpETank2img = NULL;
unsigned char	*lpETank3img = NULL;
unsigned char	*lpBulletimg = NULL;
unsigned char	*lpZhuanimg = NULL;
unsigned char   *lpTieimg = NULL;
unsigned char   *lpHomeimg = NULL;
unsigned char   tank_c = 0;
Map*			lpmap = NULL;
