/*********************************************************************************
*����:
Start_Game()
*������
�����жϲ�ʹ��Ϸ��ʼ
*�����������ã�
Main_Interface()
*�����������ã�
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
*���ߣ�
������
**********************************************************************************/

#pragma once
#include <conio.h>
#include <cstdio>
#include <graphics.h>
#include <easyx.h>//�������TCHAR��ʶ������easyx�е�outtextxyֻ����������ַ�
#pragma comment(lib,"Winmm.lib")

void Start_Game()
{
	void Main_Interface(void);
	TCHAR testChar;//��ʼ��Ϸǰ������ַ�

	testChar = _getche();//���������ַ���ʼ
	if (testChar == 27)
	{
		mciSendString("stop bgmusic", NULL, 0, NULL);
		mciSendString("close bgmusic", NULL, 0, NULL);
		Main_Interface();
	}

	setfillcolor(getpixel(5, 5));//��ȡ������ɫ
	solidrectangle(400, 200, 650, 250);//�þ���ɫ���"���������ʼ"��ס
}
