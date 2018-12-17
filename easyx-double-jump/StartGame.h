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
void PrintScord();

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
	loadimage(&diban, L"source\\use-images\\normal.png", 60, 17, true);  //加载格子图片
	IMAGE loading;
	memset(gezi, 30, sizeof(fangkuai)); //初始化清空格子数据
	setbkcolor(RGB(247, 240, 233));
	clearrectangle(0, 0, WIDTH, HEIGHT);
	for (int i = 0; i < 1; i++)				//加载界面运行两次
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
	loadimage(&bkGround, L"source\\use-images\\store_bg.png");  //加载背景

	loadimage(&my_character.character, L"source\\newimg\\bunny\\rs.png");
	ScandFangKuai();     //初始化随机方块位置
}

void StartGame() {    //游戏循环
	StartPageInit();     //游戏运行初始化
	while (my_character.alive)      //如果人物存活，游戏循环运行
	{
		StartPageUpdateWithInput();   //输入相关处理
		StartPageUpdateWithoutInput();			//输入无关的处理
	}
	running = 0;			//游戏循环停止，全局变量循行状态设为0 false
}

void StartPageUpdateWithInput() {

	if (kbhit()) // 探测用户是否有输入
	{
		char ch_temp = _getch();				//AD左右移动
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

	if (my_character.y<HEIGHT/2)		//人物位置大于屏幕1/2位置，则屏幕下移
	{
		UpdateWeizhi();
	}

	if (!CheakContact() && my_character.status)			//如果人物处于向下掉落状态（status），并且人物碰撞检测为假，则人物向下移动，并做了加速度算法，使
	{
		if (my_character.volocity < 6)
			my_character.volocity += 0.3;
		my_character.y += my_character.volocity;
	}
	else				//否则人物向上移动，并做减速处理，达到最高处，状态改变
	{
		my_character.y -= my_character.volocity;
		my_character.volocity -= 0.3;
		if (my_character.volocity <= 0)
		{
			my_character.volocity = 6;
			my_character.status = 1;
		}
	}
	putimage(0, 0, &bkGround);				//加载背景
	PrintGeZI();						//打印格子
	putimage(my_character.x, my_character.y, &my_character.character, SRCAND);		//加载人物
	PrintScord();						//打印分数板
	FlushBatchDraw();			//流处理刷新

	if (my_character.y > HEIGHT )  //人物掉出屏幕，则人物死亡
	{
		my_character.alive = false;
	}
	Sleep(15);
}
void ScandFangKuai() {     //初始化格子，分区域加载，并检测格子不重叠，重叠则重新随机
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
void UpdateWeizhi() {			//最后一排的格子位置掉出屏幕，则重新随机为第一排的格子，更新格子位置
		Record[0] += 3;
		my_character.y += 3;
	
		for (int i = 0; i < 80; i++)
		{
			gezi[i].y += 3;

		}
		if (Record[0]>=60)
		{
			score++;
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
void PrintGeZI() {		//打印后四十个格子
	for (int i = 0; i < 80; i++)
	{
		if (gezi[i].y > 10)
		{
			putimage(gezi[i].x, gezi[i].y, &diban, SRCAND);
		}

	}
}
void PrintScord() {			//打印分数板，尚未实现透明
	TCHAR  a[20];
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	settextcolor(BLACK);
	f.lfHeight = 30;                      // 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式

	wsprintf(a,L"Scorce:%d", score);
	outtextxy(0,0,a);
	
}