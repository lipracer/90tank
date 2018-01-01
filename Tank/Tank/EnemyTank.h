#pragma once
#include "FTank.h"
class EnemyTank :
	public FTank
{
public:
	EnemyTank();
	
public:
	void Move(Map* map,unsigned int Time);
	void die();
	void objectshow();

};

