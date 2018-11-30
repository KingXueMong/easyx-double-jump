#pragma once
#pragma comment(lib,"Winmm.lib")
#include"GlobalVar.h"
void LoadStartPage() {
	// 获取默认绘图窗口的 HDC 句柄
	mciSendStringW(L"open music\\EndsPage.mp3 alias jpmusic", NULL, 0, NULL);
	mciSendString(L"play jpmusic repeat", NULL, 0, NULL);

}
