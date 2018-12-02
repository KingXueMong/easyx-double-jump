#pragma once
#include "GlobalVar.h"
#pragma comment(lib,"Winmm.lib")
void StartPageUpdateWithInput();
void StartPageUpdateWithoutInput();

IMAGE bkGround;

void StartPageInit() {
	setbkcolor(RGB(247,240,233));
	loadimage(&bkGround,_T("source\\newimg\\loading.png"));
	clearrectangle(0,0, WIDTH,HEIGHT);
	putimage(150,250,&bkGround);
	FlushBatchDraw();

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

}
void StartPageUpdateWithoutInput() {

}