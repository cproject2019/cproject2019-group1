/*********************************************************************************
*����:
Sound_Effect(int soundEffect)
*������
������Ч
*�����������ã�
��
*�����������ã�
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
*���ߣ�
������
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