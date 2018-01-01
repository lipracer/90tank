#include "stdafx.h"
#include "FTank.h"
#include "GlobF.h"
#include "GlobV.h"


FTank::FTank(){ life = true; }
FTank::~FTank(){}
void FTank::Move(Map *map,unsigned int Time)
{
	if (!(Time%speend))
	{
		if (life)
		{

			if (!FindMap(map))
			{
				switch (direction)
				{
				case 0:
					loc.y -= Tank_h / 2;
					break;
				case 1:
					loc.y += Tank_h / 2;
					break;
				case 2:
					loc.x -= Tank_w / 2;
					break;
				case 3:
					loc.x += Tank_w / 2;
					break;
				default:
					break;
				}
			}
		}
	}
	
}
BOOL FTank::FindMap(Map *map)
{
	switch (direction)
	{
	case 0:
		return map->MapValu[loc.y/Bound_h-2][loc.x / Bound_w] || map->MapValu[loc.y/Bound_h-2][loc.x / Bound_w - 1];
		break;
	case 1:
		return map->MapValu[loc.y / Bound_h + 1][loc.x / Bound_w ] || map->MapValu[loc.y/Bound_h+1][loc.x / Bound_w - 1];
		break;
	case 2:
		return map->MapValu[loc.y / Bound_h - 1][loc.x / Bound_w - 2] || map->MapValu[loc.y/Bound_h][loc.x / Bound_w-2];
		break;
	case 3:
		
		return map->MapValu[loc.y / Bound_h - 1][loc.x / Bound_w + 1] || map->MapValu[loc.y/Bound_h][loc.x / Bound_w+1];
		break;
	default:
		return FALSE;
		break;
	}
	

}
void FTank::SetMap(Map *map,char value)
{
	map->MapValu[loc.y / Bound_h - 1][loc.x / Bound_w - 1] = value;
	map->MapValu[loc.y / Bound_h][loc.x / Bound_w - 1] = value;
	map->MapValu[loc.y / Bound_h - 1][loc.x / Bound_w] = value;
	map->MapValu[loc.y / Bound_h][loc.x / Bound_w] = value;
}
void FTank::attack()
{
	if (life)
	{
		bullet.lpImgdata = lpBulletimg;
		if (!bullet.life)
		{
			bullet.life = TRUE;
			bullet.direction = direction;
			switch (direction)
			{
			case 0:
				bullet.loc.x = loc.x;
				bullet.loc.y = loc.y - Bound_h;
				break;
			case 1:
				bullet.loc.x = loc.x;
				bullet.loc.y = loc.y + Bound_h;
				break;
			case 2:
				bullet.loc.x = loc.x - Bound_w;
				bullet.loc.y = loc.y;
				break;
			case 3:
				bullet.loc.x = loc.x + Bound_w;
				bullet.loc.y = loc.y;
				break;
			default:
				break;
			}

		}

	}
	

}
void::FTank::die() 
{
	life = FALSE;
	
}
