
#include "stdafx.h"
#include "stdio.h"
#include "GlobF.h"
#include "struck.h"
#include "GlobV.h"

void DrawRect(HDC hdc,Rect rect){

	MoveToEx(hdc, rect.xf, rect.yf, NULL);
	LineTo(hdc, rect.xe, rect.yf);
	LineTo(hdc,rect.xe  ,rect.ye );
	LineTo(hdc, rect.xf, rect.ye);
	LineTo(hdc, rect.xf, rect.yf);
	


};
void Object_Show(HDC hdc, Point core,Point size, unsigned char *p,unsigned int rop)
{
	::StretchDIBits(hdc, core.x-size.x/2, core.y-size.y/2, size.x, size.y, 0, 0, size.x, size.y,
	p, (LPBITMAPINFO)&bi, DIB_RGB_COLORS, rop);

}
void Init_TankImg(const char* szname, unsigned char* TankImg)
{
	FILE *pf;
	fopen_s(&pf, szname, "rb+");
	fseek(pf, 54, SEEK_SET);
	fread(TankImg, 40 * 40 * 3, 1, pf);
	fclose(pf);
	for (int i = 0; i < 40; i++)
	{
		memcpy((79 - i) * 40 * 3 + TankImg, TankImg + i * 40 * 3, 40 * 3);
	}
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			TankImg[j * 120 + i * 3 + 40 * 40 * 3 * 3] = TankImg[i * 120 + j * 3];
			TankImg[j * 120 + i * 3 + 40 * 40 * 3 * 3 + 1] = TankImg[i * 120 + j * 3 + 1];
			TankImg[j * 120 + i * 3 + 40 * 40 * 3 * 3 + 2] = TankImg[i * 120 + j * 3 + 2];
		}
	}
	unsigned char *temp = TankImg + 40 * 40 * 3;
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			temp[j * 120 + i * 3  + 40 * 40 * 3] = temp[i * 120 + j * 3];
			temp[j * 120 + i * 3 + 1 + 40 * 40 * 3] = temp[i * 120 + j * 3 + 1];
			temp[j * 120 + i * 3 + 2 + 40 * 40 * 3] = temp[i * 120 + j * 3 + 2];
		}
	}
}
void Empt()
{
	if (lpMyTankimg!=NULL)
	{
		delete []lpMyTankimg;
	}
	if (lpETank1img != NULL)
	{
		delete []lpETank1img;
	}
	if (lpETank2img != NULL)
	{
		delete []lpETank2img;
	}
	if (lpETank3img != NULL)
	{
		delete lpETank3img;
	}
	if (lpZhuanimg!=NULL)
	{
		delete []lpZhuanimg;
	}
	if (lpBulletimg!=NULL)
	{
		delete[]lpBulletimg;
	}
	if (lpTieimg!=NULL)
	{
		delete[] lpTieimg;
	}
	if (lpHomeimg != NULL)
	{
		delete[] lpHomeimg;
	}


}
void Init_MapImg(const char* szname,  unsigned char* MapImg, Point point)
{
	FILE *pf;
	fopen_s(&pf, szname, "rb+");
	fseek(pf, 54, SEEK_SET);
	fread(MapImg, point.x * point.y * 3, 1, pf);
	fclose(pf);
}
