#pragma once
#include "Map.h"
#include "Bullet.h"
#include "struck.h"
#include "Object.h"


class FTank: public Object
{
public:
	Bullet bullet;	
public:
	unsigned char speend;
public:
	FTank();
	~FTank();
	void Move(Map *map,unsigned int Time);
	virtual BOOL FindMap(Map *map);
	void SetMap(Map *map, char value);
	void attack();
	virtual void die();
	

};


