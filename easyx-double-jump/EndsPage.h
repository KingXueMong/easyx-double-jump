#pragma once
#pragma comment(lib,"Winmm.lib")
#include"GlobalVar.h"
#include<stdio.h>

#define WenJianName 
void EndsPage() {
	mciSendStringW(L"open source\\bkmusic\\EndsPage.mp3 alias jpmusic",NULL,0,NULL);
	mciSendString(L"play jpmusic repeat", NULL, 0, NULL);
	// 获取默认绘图窗口的 HDC 句柄
	HDC hdc = GetImageHDC();
	IMAGE img(WIDTH, HEIGHT);
	int width;
	int height;//获取长和宽
	const TCHAR mulu1[6][90] = { L"source\\EndsPage\\EndsPage1.png" ,L"source\\EndsPage\\EndsPage2.png",L"source\\EndsPage\\EndsPage3.png",L"source\\EndsPage\\EndsPage4.png",L"source\\EndsPage\\EndsPage5.png",L"source\\EndsPage\\EndsPage6.png" };
	// 读取图片至绘图窗口
	loadimage(&img, _T("source\\EndsPage\\EndsPage_beijing.jpg"));
	putimage(0, 0, &img);
	FlushBatchDraw();
	Sleep(1000);
	for (int i = 0; i < 6; i++)
	{
		IMAGE img_temp;
		loadimage(&img_temp, mulu1[i], 0, 0);
		width = img_temp.getwidth();
		height = img_temp.getheight();
		putimage(60, 50 + 70 * i, &img_temp, SRCAND);
		FlushBatchDraw();
		Sleep(3000);

	}
}

