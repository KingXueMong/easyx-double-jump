#pragma once
#include "GlobalVar.h"
#include <string.h>
#include <time.h>
#include<math.h>
//#include"Character.h"
#pragma comment(lib,"Winmm.lib")
void StartPageUpdateWithInput();
void StartPageUpdateWithoutInput();
void ScandFangKuai();

IMAGE bkGround;
MOUSEMSG msg;
character my_character;
int mouse_x;
int CheakContact(character *a) {
	return 0;
}

void StartPageInit() {
	memset(gezi,100,sizeof(fangkuai));
	setbkcolor(RGB(247, 240, 233));
	clearrectangle(0, 0, WIDTH, HEIGHT);
	loadimage(&bkGround, L"source\\use-images\\store_bg.png");
	for (int i = 0; i < 0; i++)				//加载界面
	{
		loadimage(&bkGround, _T("source\\newimg\\loading1.png"));
		putimage(150, 250, &bkGround);
		FlushBatchDraw();
		Sleep(1000);

		loadimage(&bkGround, _T("source\\newimg\\loading2.png"));
		putimage(150, 250, &bkGround);
		FlushBatchDraw();
		Sleep(1000);

		loadimage(&bkGround, _T("source\\newimg\\loading3.png"));
		putimage(150, 250, &bkGround);
		FlushBatchDraw();
		Sleep(1000);
	}

	loadimage(&my_character.character, L"source\\newimg\\bunny\\rs.png");

}

void StartGame() {
	StartPageInit();
	while (1)
	{
		StartPageUpdateWithInput();
		StartPageUpdateWithoutInput();
	}
}

void StartPageUpdateWithInput() {

	if (kbhit()) // 探测用户是否有输入
	{
		char ch_temp = _getch();
		if (my_character.x+60 <= WIDTH&&my_character.x>=-2)            //人物的左右移动  （先完成左右移动
		{
			if (ch_temp == 'A')
				for (int i = 0; i < 3; i++)
				{
				my_character.x-=1; // 左移动
				FlushBatchDraw();
				}
			if (ch_temp == 'D')
				for (int i = 0; i < 3; i++)
				{
					my_character.x += 1; // 左移动
					FlushBatchDraw();
				}
			if (my_character.x + 60 > WIDTH )
				my_character.x = WIDTH - 60;
			if (my_character.x<0)
				my_character.x = 0;
		}
	}


}

void StartPageUpdateWithoutInput() {
	loadimage(&bkGround, L"");
	putimage(0, 0, &bkGround);
	if (my_character.status&&!CheakContact(&my_character))
	{
		my_character.y += 1;
	}
	putimage(my_character.x, my_character.y, &my_character.character, SRCAND);
	

	FlushBatchDraw();
	Sleep(15);

}
void ScandFangKuai() {
	srand(time(NULL));
	for (int i = 0; i < 100; )
	{
		gezi[i].x = rand();
		gezi[i].y = rand();

	}
}