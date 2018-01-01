#include "stdafx.h"
#include "GlobV.h"
#include "Map.h"

Map::Map()
{

	for (int i = 0; i < 28;i++)
	{
		for (int j = 0; j < 28;j++)
		{
			if ((i==0)||(i==27)||(j==0)||(j==27))
			{
				MapValu[i][j] = tie;
			}
			else
			{
				MapValu[i][j] = zhuan;
			}
		}
	}


}
Map::~Map()
{

}
void Map::show(HDC hdc)
{
	bi.biWidth = bi.biHeight = 20;
	for (int i = 1; i < 27; i++)
	{
		for (int j = 1; j < 27; j++)
		{		
			
				switch (MapValu[i][j])
				{
				case zhuan:
					Object_Show(hdc, Point(20 * j + 10, 20 * i + 10), Point(20, 20), lpZhuanimg);
					break;
				case tie:
					Object_Show(hdc, Point(20 * j + 10, 20 * i + 10), Point(20, 20), lpTieimg);
					break;

				default:
					break;
				}

		

		}
			
		
	}
	bi.biWidth = bi.biHeight = 40;
	Object_Show(hdc, Point(280, 520), Point(40, 40), lpHomeimg);
	
}

