#ifndef __GLOBV__H
#define __GLOBV__H
#include "struck.h"
#include "Object.h"

#define Window_w 560
#define Window_h 560
#define Game_w 520
#define Game_h 520
#define Bound_w 20
#define Bound_h 20
#define Tank_w 40
#define Tank_h 40
#define Bullet_w 12
#define Bullet_h 12

extern Rect Window_Size;
extern Rect Game_Region_Size;
extern char tank_size;
extern BITMAPINFOHEADER bi;


extern HDC HDC_CompatibleDC;
extern HPEN  oldPen, newPen;
extern unsigned char *lpMyTankimg, *lpETank1img, *lpETank2img, *lpETank3img, *lpBulletimg,*lpZhuanimg,*lpTieimg,*lpHomeimg;
extern unsigned char tank_c;
//Object* object[50];
extern Map*			lpmap;



#endif