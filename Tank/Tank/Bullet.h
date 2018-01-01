#pragma once
#include "struck.h"
#include "Object.h"
#include "Map.h"


class Bullet: public Object
{
public:
	char speed;

public:
	Bullet();
	~Bullet();
	void Fly(Map *map);
	void Find_Bound();	
	BOOL Find_Map(Map *map);
	void die();
	void objectshow();
	

	
};

