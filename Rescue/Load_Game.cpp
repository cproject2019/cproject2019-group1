/*********************************************************************************
*函数:
Load_Game(int song) 
*描述：
实现游戏界面的绘制
*被本函数调用：
Play_Songs(int song)
*本函数被调用：
Game(void) 
*作者：
晁雨欣
**********************************************************************************/


#pragma once
#include <conio.h>
#include <windows.h>
#include <graphics.h>

void Load_Game(int song)
{
	void Play_Songs(int song);

	initgraph(1000, 500);//初始化绘图界面
	setbkcolor(RGB(102, 205, 0));//设置背景颜色为草绿色
	cleardevice();
	setcolor(BLACK);
	line(350, 481, 600, 481);//画输入框
	settextcolor(BLACK);
	outtextxy(800, 480, "press ESC to end the game");
	outtextxy(400, 200, "press any button to start the game");
	Play_Songs(song);//开始播放音乐
	char clearKeyboard;
	while (_kbhit())//清空键盘的缓冲区
	{
		clearKeyboard = _getche();
	}
}