#pragma once

#include <string.h>
#include <time.h>
#include<math.h>
//#include"Character.h"
#pragma comment(lib,"Winmm.lib")
void StartPageUpdateWithInput();
void StartPageUpdateWithoutInput();
void ScandFangKuai();
void PrintGeZI();
void UpdateWeizhi();

IMAGE bkGround;
character my_character;
IMAGE diban;
int Record[2] = {0,19}; //第一个数字记录单位滚动幅度，第二个记录上翻组数


int CheakContact() {		//检测任务与格子是否发生碰撞
	for (int i = 0; i < 80 && my_character.status; i++)
	{
		if (gezi[i].alive&&gezi[i].y >= 0)
		{
			if ((my_character.y + 58 >= gezi[i].y) && (my_character.y + 58 <= gezi[i].y + 17) && ((my_character.x + 6 > gezi[i].x&&my_character.x + 6 < gezi[i].x + 54) || (my_character.x + 45 > gezi[i].x&&my_character.x + 45 < gezi[i].x + 54)))
			{
				my_character.status = 0;
				return 1;
			}
		}

	}
	return 0;
}

void StartPageInit() {			//页面加载初始化
	loadimage(&diban, L"source\\use-images\\normal.png", 60, 17, true);
	IMAGE loading;
	memset(gezi, 30, sizeof(fangkuai));
	setbkcolor(RGB(247, 240, 233));
	clearrectangle(0, 0, WIDTH, HEIGHT);
	for (int i = 0; i < 1; i++)				//加载界面
	{
		loadimage(&loading, _T("source\\newimg\\loading1.png"));
		putimage(150, 250, &loading);
		FlushBatchDraw();
		Sleep(1000);

		loadimage(&loading, _T("source\\newimg\\loading2.png"));
		putimage(150, 250, &loading);
		FlushBatchDraw();
		Sleep(1000);

		loadimage(&loading, _T("source\\newimg\\loading3.png"));
		putimage(150, 250, &loading);
		FlushBatchDraw();
		Sleep(1000);
	}
	loadimage(&bkGround, L"source\\use-images\\store_bg.png");

	loadimage(&my_character.character, L"source\\newimg\\bunny\\rs.png");
	ScandFangKuai();
}

void StartGame() {
	StartPageInit();
	while (my_character.alive)
	{
		StartPageUpdateWithInput();
		StartPageUpdateWithoutInput();
	}
	running = 0;
}

void StartPageUpdateWithInput() {

	if (kbhit()) // 探测用户是否有输入
	{
		char ch_temp = _getch();
		if (my_character.x + 60 <= WIDTH && my_character.x >= -2)            //人物的左右移动  （先完成左右移动
		{
			if (ch_temp == 'A' || ch_temp == 'a')
				for (int i = 0; i < 3; i++)
				{
					my_character.x -= 1; // 左移动
					FlushBatchDraw();
				}
			if (ch_temp == 'D' || ch_temp == 'd')
				for (int i = 0; i < 3; i++)
				{
					my_character.x += 1; // 左移动
					FlushBatchDraw();
				}
			if (my_character.x + 60 > WIDTH)
				my_character.x = WIDTH - 60;
			if (my_character.x < 0)
				my_character.x = 0;
		}
	}

}

void StartPageUpdateWithoutInput() {

	if (my_character.y<HEIGHT/2)
	{
		UpdateWeizhi();
	}

	if (!CheakContact() && my_character.status)
	{
		if (my_character.volocity < 6)
			my_character.volocity += 0.3;
		my_character.y += my_character.volocity;
	}
	else
	{
		my_character.y -= my_character.volocity;
		my_character.volocity -= 0.3;
		if (my_character.volocity <= 0)
		{
			my_character.volocity = 6;
			my_character.status = 1;
		}
	}
	putimage(0, 0, &bkGround);
	PrintGeZI();
	putimage(my_character.x, my_character.y, &my_character.character, SRCAND);

	FlushBatchDraw();

	if (my_character.y > HEIGHT )
	{
		my_character.alive = false;
	}
	Sleep(15);
}
void ScandFangKuai() {
	srand(time(NULL));
	int temp = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			gezi[temp].x = 100 * k + rand() % 100;
			gezi[temp].y = 60 * i + rand() % 60-HEIGHT;
			while (i > 0 && (gezi[temp].y - gezi[temp - 4].y < 17|| abs(gezi[temp].x - gezi[temp - 1].x) < 60))
			{
				gezi[temp].x = 100 * k + rand() % 100;
				gezi[temp].y = 60 * i + rand() % 60-HEIGHT;
			}
			gezi[temp].alive = 1;
			temp++;
		}
	}
}
void UpdateWeizhi() {
		Record[0] += 3;
		my_character.y += 3;
	
		for (int i = 0; i < 80; i++)
		{
			gezi[i].y += 3;

		}
		if (Record[0]>=60)
		{
			for (int i = 0; i < 4; i++)
			{
				int temp = Record[1]*4 + i;
				gezi[temp].x = i*100 + rand() % 100;
				gezi[temp].y = rand() % 60 - HEIGHT;
				while ( i>0&&(abs(gezi[temp].x - gezi[temp - 1].x) < 60))
				{
					gezi[temp].x = i * 100 + rand() % 100;
				}
			}
			Record[1] = (Record[1]+19)%20;
			Record[0] = 0;
		}
}
void PrintGeZI() {
	for (int i = 0; i < 80; i++)
	{
		if (gezi[i].y > 10)
		{
			putimage(gezi[i].x, gezi[i].y, &diban, SRCAND);
		}

	}
}