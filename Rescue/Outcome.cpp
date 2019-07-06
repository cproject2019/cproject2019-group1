/*********************************************************************************
*函数:
Outcome(int numberOfSuccessWords, int length)
*描述：
实现结果展示界面的绘制和结果展示
*被本函数调用：
Main_Interface()
*本函数被调用：
Game(void)
*作者：
晁雨欣
**********************************************************************************/

#pragma once
#include <stdio.h>
#include <graphics.h>

void Outcome(int numberOfSuccessWords, int length)
{
	void Main_Interface();
	MOUSEMSG m;
	IMAGE imgPika;//皮卡丘图片

	initgraph(800, 480);//初始化绘图界面
	setbkcolor(WHITE);//设置背景颜色为白色
	cleardevice();
	loadimage(&imgPika, "Resource_File\\pika.jpg", 200, 200);
	putimage(550, 250, &imgPika);//苹果每次下降一个像素点
	setcolor(BLACK);
	float accuracy;
	accuracy = 100 * numberOfSuccessWords / length;//计算出正确率
	TCHAR accuracyArray[20];
	_stprintf_s(accuracyArray, sizeof(accuracyArray), _T("%6.2f"), accuracy);//将accuracy转化为字符型数据，并保存在accuracyArray中
	if (accuracy < 50)
	{
		mciSendString("open Resource_File\\endm1.mp3 alias endmusic", NULL, 0, NULL); mciSendString("play endmusic", 0, 0, 0);
		outtextxy(200, 200, "Your accuracy is                %，please continue your effort!");
		outtextxy(315, 200, accuracyArray);
		
	}
	else if (accuracy < 80)
	{
		mciSendString("open Resource_File\\endm2.mp3 alias endmusic", NULL, 0, NULL); mciSendString("play endmusic", 0, 0, 0);
		outtextxy(200, 200, "Your accuracy is                %，good job!");
		outtextxy(315, 200, accuracyArray);
		
	}
	else
	{
		mciSendString("open Resource_File\\endm3.mp3 alias endmusic", NULL, 0, NULL); mciSendString("play endmusic", 0, 0, 0);
		outtextxy(200, 200, "Your accuracy is                 %，excellent!");
		outtextxy(315, 200, accuracyArray);
		
	}
	
	while (true)
	{
		m = GetMouseMsg();
		if (0 <= m.x&&m.x <= 800 && 0 <= m.y&&m.y <= 480 && WM_LBUTTONDOWN == m.uMsg)//当鼠标点击，返回主界面
		{
			mciSendString("stop endmusic", NULL, 0, NULL);//停止播放结束音效
			mciSendString("close endmusic", NULL, 0, NULL);//关停结束音效
			Main_Interface();
		}
	}
}