#pragma once
#include<graphics.h>//用easyx图形库绘图
#include<easyx.h>
#include<stdio.h>
#include<conio.h>



/*********************************************************************************
*函数:
Main_Interface(void)
*描述：
实现主界面绘制和功能选择
*被本函数调用：
Game()
Load_Main_Interface(void)
Score_Interface()
Setting_Interface()
*本函数被调用：
Accuracy(int * accuracyArray)
Create_All_Wrodlist(int wordMaxSize)
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
main(void)
Outcome(int numberOfSuccessWords, int length)
Setting_Interface(void)
Start_Game()
*作者：
黎晏源
**********************************************************************************/
void Main_Interface(void)
{
	void Game(void);	//游戏函数
	void Score_Interface(void);	//打字速度与准确度统计函数
	void Setting_Interface(void);	//设置游戏参数函数
	void Load_Main_Interface(void);//主界面初始化函数

	Load_Main_Interface();

	while (true)
	{
		MOUSEMSG m;			//鼠标指针变量
		m = GetMouseMsg();	//获取鼠标点击信息
		if (WM_LBUTTONDOWN == m.uMsg && m.x >= 250 && m.x <= 300 && m.y >= 80 && m.y <= 120)
		{
			Setting_Interface();
		}
		else if (WM_LBUTTONDOWN == m.uMsg && m.x >= 500 && m.x <= 550 && m.y >= 110 && m.y <= 150)
		{
			Game();
		}
		else if (WM_LBUTTONDOWN == m.uMsg && m.x >= 260 && m.x <= 310 && m.y >= 230 && m.y <= 270)
		{
			Score_Interface();
		}
	}	//对鼠标点击位置进行判断
}



/*********************************************************************************
*函数:
Load_Main_Interface(void)
*描述：
绘制主界面
*被本函数调用：
无
*本函数被调用：
Main_Interface(void)
*输入参数：
无
*返回值：
无
*作者：
黎晏源
**********************************************************************************/
void Load_Main_Interface(void)
{
	initgraph(800, 480);				//初始化主界面
	setbkcolor(WHITE);					//设定背景颜色
	cleardevice();						//按照背景颜色对背景上色
	setbkcolor(RGB(211, 24, 31));		//设置文字颜色
	settextstyle(30, 0, TEXT("楷体"));	//在指定位置输出文本
	IMAGE img;							//设置图片变量
	loadimage(&img, "Resource_File\\AppleTree.jpg", 800, 480);//加载图片，并设置图片大小
	putimage(0, 0, &img);				//在指定位置插入图片
	outtextxy(230, 100, TEXT("Setting"));
	outtextxy(500, 130, TEXT("Game"));
	outtextxy(255, 245, TEXT("Score"));	//初始化界面，绘图
}