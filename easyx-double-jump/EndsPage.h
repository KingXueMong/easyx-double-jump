#pragma once
#include"GlobalVar.h"
#include<stdio.h>
#define WenJianName 
void EndsPage() {
	// 获取默认绘图窗口的 HDC 句柄
	HDC hdc = GetImageHDC();
	IMAGE img(WIDTH, HEIGHT);
	IMAGE img_temp;
	const TCHAR mulu[6][60] = { L"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\1.png" ,L"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\2.png",L"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\3.png",L"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\4.png",L"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\5.png",L"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\6.png" };
	// 读取图片至绘图窗口
	loadimage(&img, _T("C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\endsbeijing.jpg"));
	putimage(0, 0, &img);
	FlushBatchDraw();
	Sleep(1000);
	for (int i = 0; i < 6; i++)
	{
		getimage(&img_temp, 0, 0,0,0 );
		loadimage(&img_temp, mulu[i]);
		putimage(70, i *70, &img_temp);
		FlushBatchDraw();
		Sleep(3000);
	}
}
