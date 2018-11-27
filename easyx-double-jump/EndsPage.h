#pragma once
#include"GlobalVar.h"
#include<stdio.h>
#define WenJianName ""
void EndsPage() {
	// 获取默认绘图窗口的 HDC 句柄
	HDC hdc = GetImageHDC();
	IMAGE img(WIDTH, HEIGHT);
	IMAGE img_temp;
	const char mulu[6][60] = { "C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\endsbeijing.jpg" ,"C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\2.png","C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\3.png","C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\4.png","C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\5.png","C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\6.png" };
	// 读取图片至绘图窗口
	loadimage(&img, _T("C:\\Users\\kingxue\\Desktop\\游戏\\sucai\\endsbeijing.jpg"));
	putimage(0, 0, &img);
	FlushBatchDraw();
	Sleep(1000);
	for (int i = 0; i < 6; i++)
	{

	}
}
