#include "stdafx.h"
#include "EnemyTank.h"
#include "GlobF.h"
#include "GlobV.h"

EnemyTank::EnemyTank(){ type = Etank; bullet.type = typeEnBullet; }

void EnemyTank::Move(Map* map,unsigned int Time)
{
	if (life)
	{
		FTank::SetMap(map, 0);
		FTank::Move(map,Time);
		//objectshow(HDC_CompatibleDC);
		FTank::SetMap(map, Etank);
	}

	

}
void EnemyTank::die()
{
	life=false;
	SetMap(lpmap, none);
}
void EnemyTank::objectshow()
{
	Object_Show(HDC_CompatibleDC, loc, Point(Tank_w, Tank_h), lpImgdata + (40 * 40 * 3)*direction);
}



