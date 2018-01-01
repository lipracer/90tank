#include "stdafx.h"
#include "GlobV.h"
#include "GlobF.h"
#include "MyTank.h"

MyTank::MyTank(){ type = Mtank; bullet.type = typeMyBullet; speend = 1; };

void MyTank::Move(Map* map,unsigned int Time)
{
	if (life)
	{
		FTank::SetMap(map, 0);
		FTank::Move(map,Time);
		FTank::SetMap(map, Mtank);
		
	}



}
void MyTank::objectshow()
{
	if (life)
	{
		Object_Show(HDC_CompatibleDC, loc, Point(Tank_w, Tank_h), lpImgdata + (40 * 40 * 3)*direction);
	}

}

