#pragma once
#include "Map.h"
class GameManage
{
public:
	HBITMAP h1;
	int Pass;
	unsigned char red_c;
	unsigned char fast_c;
	unsigned char strong_c;
	unsigned char kind_c;
public:
	GameManage(HWND hWnd);
	~GameManage();
	void InitPass(Map* map);
};

