/*********************************************************************************
*����:
Load_Game(int song) 
*������
ʵ����Ϸ����Ļ���
*�����������ã�
Play_Songs(int song)
*�����������ã�
Game(void) 
*���ߣ�
������
**********************************************************************************/


#pragma once
#include <conio.h>
#include <windows.h>
#include <graphics.h>

void Load_Game(int song)
{
	void Play_Songs(int song);

	initgraph(1000, 500);//��ʼ����ͼ����
	setbkcolor(RGB(102, 205, 0));//���ñ�����ɫΪ����ɫ
	cleardevice();
	setcolor(BLACK);
	line(350, 481, 600, 481);//�������
	settextcolor(BLACK);
	outtextxy(800, 480, "press ESC to end the game");
	outtextxy(400, 200, "press any button to start the game");
	Play_Songs(song);//��ʼ��������
	char clearKeyboard;
	while (_kbhit())//��ռ��̵Ļ�����
	{
		clearKeyboard = _getche();
	}
}