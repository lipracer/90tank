// tank.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "tank.h"
#include "Object.h"
#include "EnemyTank.h"
#include "MyTank.h"
#include "GlobF.h"
#include "GlobV.h"
#include "GameManage.h"

#define MAX_LOADSTRING 100
#define ETC 3

HINSTANCE hInst;
TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];
unsigned int speen_ctr = 0;
unsigned char Object::obj_c = 0;
Object* Object::lpobj[50] = {};
HBITMAP h1;
Map map;
EnemyTank etank[ETC];
MyTank mytank;
HWND hWnd;
int dx=0, dy=0;

// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{


	lpmap = &map;
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_TANK, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	//hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TANK)); 


	DWORD tPre=0, tCur=0;
	while (1)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message==WM_QUIT)
			{
				break;
			}
		}
		else
		{
			tCur = GetTickCount();
			if (tCur-tPre>10)
			{
				tPre = tCur;
				speen_ctr++;
				if (!(speen_ctr % 70))
				{
					for (int i = 0; i < ETC; i++)
					{
						etank[i].direction = rand() % 4;

						etank[i].attack();
					}
				}
				for (int i = 0; i < ETC; i++)
				{
					//etank[i].direction = rand() % 4;
					etank[i].Move(&map, speen_ctr);
					etank[i].attack();
				}

				for (int i = 0; i < ETC; i++)
				{
					etank[i].bullet.Fly(&map);
				}

				StretchBlt(HDC_CompatibleDC, 0, 0, Window_w, Window_h, HDC_CompatibleDC, 0, 0, Window_w, 560, SRCINVERT);
				for (int i = 0; i < 50; i++)
				{
					if (mytank.lpobj[i] && mytank.lpobj[i]->life)
					{
						for (int j = 0; j < 50; j++)
						{
							if (mytank.lpobj[j] && mytank.lpobj[j]->life && (j != i))
							{
								if ((mytank.lpobj[i]->type == typeEnBullet) && (mytank.lpobj[j]->type == typeMyBullet))
								{
									if ((mytank.lpobj[i]->loc.x == mytank.lpobj[j]->loc.x) && \
										(mytank.lpobj[i]->loc.y == mytank.lpobj[j]->loc.y)){
										mytank.lpobj[i]->die();
										mytank.lpobj[j]->die();
									}
									if ((260 <= mytank.lpobj[i]->loc.x <= 300) && (500 <= mytank.lpobj[i]->loc.y <= 540))
									{
										mytank.lpobj[i]->die();
									}

								}
								if (((mytank.lpobj[i]->type == Etank) && (mytank.lpobj[j]->type == typeMyBullet))\
									|| ((mytank.lpobj[i]->type == Mtank) && (mytank.lpobj[j]->type == typeEnBullet)))
								{
									dx = mytank.lpobj[i]->loc.x - mytank.lpobj[j]->loc.x;
									dx = dx*dx;
									dy = mytank.lpobj[i]->loc.y - mytank.lpobj[j]->loc.y;
									dy = dy*dy;

									if (dx + dy <= 800)
									{
										mytank.lpobj[i]->die();
										mytank.lpobj[j]->die();
									}

								}
							}
						}
						mytank.lpobj[i]->objectshow();
					}
					if (mytank.lpobj[i] && mytank.lpobj[i]->life)
					{
						//mytank.lpobj[i]->objectshow();
					}
				}
				//mytank.objectshow();
				mytank.bullet.Fly(&map);
				map.show(HDC_CompatibleDC);
				//char p[32];
				//wsprintfA(p,"%d",speen_ctr);
				//TextOutA(HDC_CompatibleDC,0,0,p,32);
				DrawRect(HDC_CompatibleDC, Game_Region_Size);
				::InvalidateRect(hWnd, NULL, FALSE);
			}
		}
	}
	return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TANK));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW - 3);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCE(IDC_TANK);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{


	hInst = hInstance; // 将实例句柄存储在全局变量中


	hWnd = CreateWindowEx(NULL, szWindowClass, szTitle,
		WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_POPUP,
		Window_Size.xf, Window_Size.yf, Window_Size.xe,
		Window_Size.ye, NULL, NULL, hInstance, NULL);




	if (!hWnd)
	{
		return FALSE;
	}

	GameManage* gm = new GameManage(hWnd);
	gm->InitPass(&map);

	for (int i = 0; i < ETC; i++)
	{
		if (i % 3 == 0)
		{
			etank[i].lpImgdata = lpETank1img;
			etank[i].speend = 10;
		}
		if (i % 3 == 1)
		{
			etank[i].lpImgdata = lpETank2img;
			etank[i].speend = 40;
		}
		if (i % 3 == 2)
		{
			etank[i].lpImgdata = lpETank3img;
			etank[i].speend = 80;
		}
	}
	mytank.lpImgdata = lpMyTankimg;
	for (int i = 0; i < ETC; i++)
	{
		etank[i].loc = Point(40 + (i % 3) * 240, 40);


	}
	mytank.loc = Point(220, 520);
	map.show(HDC_CompatibleDC);
	::SetTimer(hWnd,1,1,NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			if (mytank.direction == 0)
			{
				mytank.Move(&map,0);
			}
			else
				mytank.direction = 0;


			break;
		case VK_DOWN:
			if (mytank.direction == 1)
			{
				mytank.Move(&map,0);
			}
			else
				mytank.direction = 1;

			break;
		case VK_LEFT:
			if (mytank.direction == 2)
			{
				mytank.Move(&map,0);
			}
			else
				mytank.direction = 2;

			break;
		case VK_RIGHT:
			if (mytank.direction == 3)
			{
				mytank.Move(&map,0);
			}
			else
				mytank.direction = 3;

			break;
		case 65:
			mytank.attack();

			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		//mytank.direction = 4;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		StretchBlt(hdc, 0, 0, Window_w * 2, Window_h, HDC_CompatibleDC, 0, 0, Window_w * 2, Window_h, SRCCOPY);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
