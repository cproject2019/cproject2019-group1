/*********************************************************************************
*函数:
Sound_Effect(int soundEffect)
*描述：
播放音效
*被本函数调用：
无
*本函数被调用：
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
*作者：
晁雨欣
**********************************************************************************/
#pragma once
#include <graphics.h>

void Sound_Effect(int soundEffect)
{
	int tune;
	switch (soundEffect)
	{
	case 1: tune = 250; Beep(tune, 100); break;
	case 0: break;
	}
}