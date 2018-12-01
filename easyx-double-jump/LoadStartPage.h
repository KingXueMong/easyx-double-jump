#pragma once
#pragma comment(lib,"Winmm.lib")
#include"GlobalVar.h"
bool Button1Click=false,Button2Click=false;
void UpdateWithInput();
void UpdateWithoutInput();
IMAGE Button1,Button2;
IMAGE img;
IMAGE Name1, Name2, Name3;

void LoadStartPage() {
	// 获取默认绘图窗口的 HDC 句柄
	mciSendStringW(L"open music\\LoadStartPage.mp3 alias jpmusic", NULL, 0, NULL);
	mciSendString(L"play jpmusic repeat", NULL, 0, NULL);
	while (g_now_working_page==0)
	{
		UpdateWithoutInput();
		UpdateWithInput();
	}
}

void UpdateWithoutInput() {
	loadimage(&img,_T("source\\LoadStartPage_beijing.jpg"));
	loadimage(&Button1, _T("source\\LoadStartPagePageButton1.png"));
	loadimage(&Name1, _T("source\\LoadStartPagePageName1.png"));
	loadimage(&Name2, _T("source\\LoadStartPagePageName2.png"));
	loadimage(&Name3, _T("source\\LoadStartPagePageName3.png"));

	if (Button1Click)								//检测按钮1是否被点击
		loadimage(&Button1, _T("source\\LoadStartPagePageButton1_c.png"));
	else
		loadimage(&Button1, _T("source\\LoadStartPagePageButton1.png"));

	if (Button2Click)								//检测按钮2是否被点击
		loadimage(&Button2, _T("source\\LoadStartPagePageButton2_c.png"));
	else
		loadimage(&Button2, _T("source\\LoadStartPagePageButton2.png"));

	putimage(0,0,&img);								//加载图片

	putimage(LOAD_START_PAGE_NAME_1_X, LOAD_START_PAGE_NAME_1_Y, &Name1, SRCAND);
	putimage(LOAD_START_PAGE_NAME_2_X, LOAD_START_PAGE_NAME_2_Y, &Name2, SRCAND);
	putimage(LOAD_START_PAGE_NAME_3_X, LOAD_START_PAGE_NAME_3_Y, &Name3, SRCAND);

	putimage(LOAD_START_PAGE_BUTTON_1_X, LOAD_START_PAGE_BUTTON_1_Y, &Button1, SRCAND);
	putimage(LOAD_START_PAGE_BUTTON_2_X, LOAD_START_PAGE_BUTTON_2_Y, &Button2, SRCAND);
	FlushBatchDraw();

}
void UpdateWithInput() {
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
	}
}