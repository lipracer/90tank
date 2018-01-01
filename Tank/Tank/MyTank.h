#pragma once
#include "FTank.h"
class MyTank :public FTank
{
public:
	MyTank();

	void Move(Map *map,unsigned int Time);
	void objectshow();

};

