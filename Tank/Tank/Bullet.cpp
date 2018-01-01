#include "stdafx.h"
#include "Bullet.h"
#include "GlobV.h"
#include "GlobF.h"
#include "struck.h"


Bullet::Bullet()
{
	life = false;
	speed = 3;

}


Bullet::~Bullet()
{
}


void Bullet::Fly(Map *map)
{
	//if (){}
	if (loc.x <= Game_Region_Size.xf || loc.y <= Game_Region_Size.yf||loc.x>=Game_Region_Size.xe||loc.y>=Game_Region_Size.ye)
	{
		life = false;
	}
	if (life)
	{
		Find_Map(map);
		switch (direction)
		{
		case 0:
			loc.y -= speed;
			break;
		case 1:
			loc.y += speed;
			break;
		case 2:
			loc.x -= speed;
			break;
		case 3:
			loc.x += speed;
			break;
		default:
			break;
		}
		bi.biWidth = Bullet_w;
		bi.biHeight = Bullet_h;
		bi.biWidth = Tank_w;
		bi.biHeight = Tank_h;
	}

}

BOOL Bullet::Find_Map(Map *map)
{
	switch (direction)
	{

	case 0:

		if (map->MapValu[loc.y / 20 - 1][loc.x / 20] == zhuan)
		{
			map->MapValu[loc.y / 20 - 1][loc.x / 20] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20 - 1][loc.x / 20] == tie)
		{
			die();
		}
		if (map->MapValu[loc.y / 20 - 1][loc.x / 20 - 1] == zhuan)
		{
			map->MapValu[loc.y / 20 - 1][loc.x / 20 - 1] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20 - 1][loc.x / 20 - 1] == tie)
		{
			die();
		}
		break;
	case 1:

		if (map->MapValu[loc.y / 20][loc.x / 20] == zhuan)
		{
			map->MapValu[loc.y / 20][loc.x / 20] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20][loc.x / 20] == tie)
		{
			die();
		}
		if (map->MapValu[loc.y / 20][loc.x / 20 - 1] == zhuan)
		{
			map->MapValu[loc.y / 20][loc.x / 20 - 1] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20][loc.x / 20 - 1] == tie)
		{
			die();
		}
		break;
	case 2:

		if (map->MapValu[loc.y / 20 - 1][loc.x / 20 - 1] == zhuan)
		{
			map->MapValu[loc.y / 20 - 1][loc.x / 20 - 1] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20 - 1][loc.x / 20 - 1] == tie)
		{
			die();
		}
		if (map->MapValu[loc.y / 20][loc.x / 20 - 1] == zhuan)
		{
			map->MapValu[loc.y / 20][loc.x / 20 - 1] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20][loc.x / 20 - 1] == tie)
		{
			die();
		}
		break;
	case 3:
		if (map->MapValu[loc.y / 20 - 1][loc.x / 20] == zhuan)
		{
			map->MapValu[loc.y / 20 - 1][loc.x / 20] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20 - 1][loc.x / 20] == tie)
		{
			die();
		}
		if (map->MapValu[loc.y / 20][loc.x / 20] == zhuan)
		{
			map->MapValu[loc.y / 20][loc.x / 20] = 0;
			die();
		}
		else if (map->MapValu[loc.y / 20][loc.x / 20] == tie)
		{
			die();
		}
		break;
	default:
		break;
	}
	return TRUE;
};
void Bullet::die()
{
	life = false;

}
void Bullet::objectshow()
{
	bi.biWidth = Bullet_w;
	bi.biHeight = Bullet_h;
	Object_Show(HDC_CompatibleDC, loc, Point(Bullet_w, Bullet_h), lpImgdata, SRCPAINT);
	bi.biWidth = Tank_w;
	bi.biHeight = Tank_h;
}



