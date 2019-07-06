#pragma once
#include<graphics.h>
#include<easyx.h>
#include<stdio.h>



/*********************************************************************************
*函数:
Speed(int * speedArray, int * accuracyArray)
*描述：
展示速度信息
*被本函数调用：
Accuracy(int *accuracyArray)
*本函数被调用：
Score_Interface(void)
*作者：
黎晏源
**********************************************************************************/
void Speed(int* speedArray, int* accuracyArray)//打字速度统计函数
{
	MOUSEMSG m;//设置鼠标指针变量
	TCHAR s[10], t[10];
	int i = 0;

	void Laod_Speed_Frame(void);

	Laod_Speed_Frame();

	/*速度数据描点作图*/
	for (i = 1; i < 13; i++)
	{
		settextstyle(20, 0, TEXT("楷体"));
		_stprintf_s(t, _T("%d"), 5 * i);//将数字转化为文本输出
		outtextxy(65, 410 - 25 * i, t);
		line(100, 410 - 25 * i, 110, 410 - 25 * i);
	}//完成y轴上画线
	for (i = 1; i < 11; i++)
	{
		_stprintf_s(t, sizeof(t), _T("%d"), i);
		outtextxy(100 + 50 * i, 425, t);
		line(100 + 50 * i, 420, 100 + 50 * i, 410);
	}//完成x轴上画线
	for (i = 0; i < 10; i++)
	{
		settextstyle(20, 0, TEXT("楷体"));
		_stprintf_s(s, sizeof(s), _T("%d"), speedArray[i]);
		outtextxy(150 + 50 * i, -5 * speedArray[i] + 395, s);
		solidcircle(150 + 50 * i, -5 * speedArray[i] + 420, 5);
	}//根据准确率数组提供的打字速度的值画点
	for (i = 0; i<9; i++)
	{
		setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 2);
		line(150 + 50 * i, -5 * speedArray[i] + 420, 150 + 50 * (i + 1), -5 * speedArray[i + 1] + 420);
	}//将相邻的点用虚线依次相连
	while (true)
	{
		m = GetMouseMsg();
		if (0 <= m.x&&m.x <= 800 && 0 <= m.y&&m.y <= 480 && WM_LBUTTONDOWN == m.uMsg)
		{
			void Accuracy(int* accuracyArray);
			Accuracy(accuracyArray);
		}
	}//判断鼠标点击位置，实现鼠标点击屏幕时跳转至统计准确率函数界面
}



/*********************************************************************************
*函数:
Laod_Speed_Frame(void)
*描述：
绘制展示速度所用的界面
*被本函数调用：
无
*本函数被调用：
Speed(int * speedArray, int * accuracyArray)
*作者：
黎晏源
**********************************************************************************/
void Laod_Speed_Frame(void)
{
	setbkcolor(BLACK);
	cleardevice();
	setcolor(WHITE);
	settextstyle(20, 0, TEXT("楷体"));
	settextcolor(WHITE);
	line(100, 450, 100, 50);
	line(20, 420, 700, 420);
	line(100, 50, 85, 65);
	line(100, 50, 115, 65);
	line(700, 420, 685, 435);
	line(700, 420, 685, 405);
	outtextxy(10, 50, TEXT("Speeed"));
	outtextxy(5, 70, TEXT("words/min"));
	outtextxy(700, 440, TEXT("Times"));
	outtextxy(90, 425, TEXT("0"));//打字速度函数界面初始绘图
}