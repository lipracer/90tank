#ifndef __MAP__H
#define __MAP__H
#include "struck.h"
//#include "GlobV.h"
#include "GlobF.h"

class Map
{
public:
	char MapValu[28][28];

public:
	Map();
	~Map();
	void show(HDC hdc);

};
#endif