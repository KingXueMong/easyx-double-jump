#pragma once
#pragma comment(lib,"Winmm.lib")
#include"GlobalVar.h"
bool Button1Click=false,Button2Click=false;
void LoadStartPageUpdateWithInput();
void LoadStartPageUpdateWithoutInput();
void LoadStartPageInit();
IMAGE LoadStartPageButton1,Button2;
IMAGE LoadStartPageBKGround;
IMAGE Name1, Name2, Name3;
IMAGE GuaJian1, GuaJian2, GuaJian3;

void LoadStartPage() {
	// 获取默认绘图窗口的 HDC 句柄
	mciSendStringW(L"open source\\bkmusic\\LoadStartPage.mp3 alias jpmusic", NULL, 0, NULL);
	mciSendString(L"play jpmusic repeat", NULL, 0, NULL);
	LoadStartPageInit();
	while (g_now_working_page==0)
	{
		LoadStartPageUpdateWithoutInput();
		LoadStartPageUpdateWithInput();
	}
}

void LoadStartPageInit() {
	loadimage(&GuaJian1, _T("source\\newimg\\doodlejump.png"),206,50);
	loadimage(&GuaJian2, _T("source\\LoadStartPage\\LoadStartPage_beijing.jpg"));
	loadimage(&GuaJian3, _T("source\\LoadStartPage\\LoadStartPage_beijing.jpg"));

	loadimage(&LoadStartPageBKGround, _T("source\\newimg\\pausecover.png"));
	loadimage(&LoadStartPageButton1, _T("source\\LoadStartPage\\LoadStartPagePageButton1.png"));
	loadimage(&Name1, _T("source\\LoadStartPage\\LoadStartPagePageName1.png"));
	loadimage(&Name2, _T("source\\LoadStartPage\\LoadStartPagePageName2.png"));
	loadimage(&Name3, _T("source\\LoadStartPage\\LoadStartPagePageName3.png"));

}
void LoadStartPageUpdateWithoutInput() {
	if (Button1Click)								//检测按钮1是否被点击
		loadimage(&LoadStartPageButton1, _T("source\\LoadStartPage\\LoadStartPagePageButton1_c.png"));
	else
		loadimage(&LoadStartPageButton1, _T("source\\LoadStartPage\\LoadStartPagePageButton1.png"));

	if (Button2Click)								//检测按钮2是否被点击
		loadimage(&Button2, _T("source\\LoadStartPage\\LoadStartPagePageButton2_c.png"));
	else
		loadimage(&Button2, _T("source\\LoadStartPage\\LoadStartPagePageButton2.png"));

	putimage(0,0,&LoadStartPageBKGround);								//加载图片

	putimage(20,30,&GuaJian1,SRCAND);

	putimage(LOAD_START_PAGE_NAME_1_X, LOAD_START_PAGE_NAME_1_Y, &Name1, SRCAND);
	putimage(LOAD_START_PAGE_NAME_2_X, LOAD_START_PAGE_NAME_2_Y, &Name2, SRCAND);
	putimage(LOAD_START_PAGE_NAME_3_X, LOAD_START_PAGE_NAME_3_Y, &Name3, SRCAND);

	putimage(LOAD_START_PAGE_BUTTON_1_X, LOAD_START_PAGE_BUTTON_1_Y, &LoadStartPageButton1, SRCAND);
	putimage(LOAD_START_PAGE_BUTTON_2_X, LOAD_START_PAGE_BUTTON_2_Y, &Button2, SRCAND);
	FlushBatchDraw();

}
void LoadStartPageUpdateWithInput() {
	MOUSEMSG msg;
	if (MouseHit())
	{
		msg = GetMouseMsg();
		if (msg.uMsg==WM_MOUSEMOVE)
		{
			if (msg.x >= LOAD_START_PAGE_BUTTON_1_X && msg.x <= LOAD_START_PAGE_BUTTON_1_X + LOAD_START_PAGE_BUTTON_WIDTH&& msg.y >= LOAD_START_PAGE_BUTTON_1_Y && msg.y <= LOAD_START_PAGE_BUTTON_1_Y + LOAD_START_PAGE_BUTTON_HEIGHT)
				Button1Click = true;
			else
				Button1Click = false;
			if (msg.x >= LOAD_START_PAGE_BUTTON_2_X && msg.x <= LOAD_START_PAGE_BUTTON_2_X + LOAD_START_PAGE_BUTTON_WIDTH && msg.y >= LOAD_START_PAGE_BUTTON_2_Y && msg.y <= LOAD_START_PAGE_BUTTON_2_Y + LOAD_START_PAGE_BUTTON_HEIGHT)
				Button2Click = true;
			else
				Button2Click = false;
		}
		if (msg.uMsg==WM_LBUTTONDOWN)
		{
			if (msg.x >= LOAD_START_PAGE_BUTTON_1_X && msg.x <= LOAD_START_PAGE_BUTTON_1_X + LOAD_START_PAGE_BUTTON_WIDTH && msg.y >= LOAD_START_PAGE_BUTTON_1_Y && msg.y <= LOAD_START_PAGE_BUTTON_1_Y + LOAD_START_PAGE_BUTTON_HEIGHT)
				g_now_working_page = 1;
			if (msg.x >= LOAD_START_PAGE_BUTTON_2_X && msg.x <= LOAD_START_PAGE_BUTTON_2_X + LOAD_START_PAGE_BUTTON_WIDTH && msg.y >= LOAD_START_PAGE_BUTTON_2_Y && msg.y <= LOAD_START_PAGE_BUTTON_2_Y + LOAD_START_PAGE_BUTTON_HEIGHT)
				g_now_working_page = 2;

		}
	}
}