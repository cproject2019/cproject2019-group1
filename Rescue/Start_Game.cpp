/*********************************************************************************
*函数:
Start_Game()
*描述：
条件判断并使游戏开始
*被本函数调用：
Main_Interface()
*本函数被调用：
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
*作者：
晁雨欣
**********************************************************************************/

#pragma once
#include <conio.h>
#include <cstdio>
#include <graphics.h>
#include <easyx.h>//如果不用TCHAR标识符，则easyx中的outtextxy只能输出单个字符
#pragma comment(lib,"Winmm.lib")

void Start_Game()
{
	void Main_Interface(void);
	TCHAR testChar;//开始游戏前输入的字符

	testChar = _getche();//输入任意字符后开始
	if (testChar == 27)
	{
		mciSendString("stop bgmusic", NULL, 0, NULL);
		mciSendString("close bgmusic", NULL, 0, NULL);
		Main_Interface();
	}

	setfillcolor(getpixel(5, 5));//获取背景颜色
	solidrectangle(400, 200, 650, 250);//用矩形色块把"按任意键开始"挡住
}
