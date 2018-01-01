#include "stdafx.h"
#include "GameManage.h"
#include "GlobV.h"
#include "GlobF.h"
#include "stdio.h"


GameManage::GameManage(HWND hWnd)
{
	lpMyTankimg = new unsigned char[40 * 40 * 3 * 4];
	lpETank1img = new unsigned char[40 * 40 * 3 * 4];
	lpETank2img = new unsigned char[40 * 40 * 3 * 4];
	lpETank3img = new unsigned char[40 * 40 * 3 * 4];
	lpBulletimg = new unsigned char[12 * 12 * 3];
	lpZhuanimg = new unsigned char[20 * 20 * 3];
	lpTieimg = new unsigned char[20 * 20 * 3];
	lpHomeimg = new unsigned char[40 * 40 * 3];
	Init_TankImg("../Img/my_up.bmp", lpMyTankimg);
	Init_TankImg("../Img/1.bmp", lpETank1img);
	Init_TankImg("../Img/2.bmp", lpETank2img);
	Init_TankImg("../Img/3.bmp", lpETank3img);
	Init_MapImg("../Img/Bullet.bmp", lpBulletimg,Point(12,12));
	Init_MapImg("../Img/zhuan.bmp",lpZhuanimg);
	Init_MapImg("../Img/tie.bmp",lpTieimg);
	Init_MapImg("../Img/home.bmp", lpHomeimg,Point(40,40));	
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = tank_size;
	bi.biHeight = tank_size;
	bi.biPlanes = 1;
	bi.biBitCount = 24;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 8;
	bi.biClrImportant = 0;
	HDC_CompatibleDC = CreateCompatibleDC(GetDC(hWnd));


	h1 = CreateCompatibleBitmap(GetDC(hWnd), 560*2, 560);
	SelectObject(HDC_CompatibleDC, h1);



	HPEN newPen = ::CreatePen(0, 5, 255);
	HPEN oldPen = (HPEN)SelectObject(HDC_CompatibleDC, newPen);
	DrawRect(HDC_CompatibleDC, Game_Region_Size);
	Pass = 1;
}


GameManage::~GameManage()
{
	Empt();
	SelectObject(HDC_CompatibleDC, oldPen);
	DeleteObject(newPen);
}
void GameManage::InitPass(Map* map)
{
	char p[20];
	wsprintfA(p,"../%dpass",Pass);
	FILE *pf;
	fopen_s(&pf, p, "rb+");
	for (int i = 0; i < 28;i++)
	{
		fread(map->MapValu[i], 28, 1, pf);
	}	
	fclose(pf);
	//map->MapValu[26][14] = Home;
	fast_c = 4;
	strong_c = 4;
	red_c = 4;
	kind_c = 4;
	tank_c = fast_c + strong_c + kind_c + red_c + 2;

}
