#ifndef __STRUCT__H
#define __STRUCT__H
#define none				0
#define zhuan				1
#define tie					2
#define cao					3
#define shui				4
#define Mtank				5
#define Etank				6

#define typeMyBullet		7
#define typeEnBullet		8
#define Home				9



struct Rect{
	long xf;
	long yf;
	long xe;
	long ye;
};
struct Point
{
	long x;
	long y;
	Point(){};
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

};

#endif