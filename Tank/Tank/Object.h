#pragma once
#include "struck.h"
#include "Map.h"
//#include "GlobV.h"
class Object
{
public:
	unsigned char *lpImgdata;
	Point loc;
	char direction;
	unsigned char life;
	char type;
	static Object* lpobj[50];
	static unsigned char obj_c;
public:
	Object();
	~Object();
	virtual void die();
	virtual BOOL FindMap(Map* map);
	virtual void objectshow();
};

