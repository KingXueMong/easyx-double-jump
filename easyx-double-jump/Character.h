#pragma once
#pragma comment(lib,"Winmm.lib")
#include"GlobalVar.h"		//		调用时请调用main
void GetTheEnter(int *x, int *y)
{
	int ch_temp;
	if (kbhit()) // 探测用户是否有输入
	{
		char ch_temp = _getch();
		if (*x < WIDTH)            //人物的左右移动  （先完成左右移动
		{
			if (ch_temp == 'A')
				(*x)++; // 左移动
			if (ch_temp == 'D');
			(*x)--; // 右移动
		}
		else
			x = 0;        // 超过范围 就到界面的另一边
	}
}
	void IsCharacterDie(int y) //判断角色是否死亡
	{
		if (y < HEIGHT)

		else
			g_now_working_page = 2; // 角色死亡
	}

//void MainCharacter()//控制人物移动的函数 加载资源
//{
//	int character_location_x = WIDTH / 2; //人物位置初始化
//	int character_location_y = HEIGHT;
//	 获取默认绘图窗口的 HDC 句柄
//	HDC hdc = GetImageHDC();
//	IMAGE Character_img(WIDTH, HEIGHT);
//	loadimage(&Character_img, _T("source\\newimg\\ice\\ls.png"));
//	while (1)
//	{
//		putimage(character_location_x, character_location_y, &Character_img);
//		GetTheEnter(character_location_x, character_location_y);
//		IsCharacterDie(character_location_y);
//	}
//
//}
