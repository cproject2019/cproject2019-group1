/*********************************************************************************
*����:
Outcome(int numberOfSuccessWords, int length)
*������
ʵ�ֽ��չʾ����Ļ��ƺͽ��չʾ
*�����������ã�
Main_Interface()
*�����������ã�
Game(void)
*���ߣ�
������
**********************************************************************************/

#pragma once
#include <stdio.h>
#include <graphics.h>

void Outcome(int numberOfSuccessWords, int length)
{
	void Main_Interface();
	MOUSEMSG m;
	IMAGE imgPika;//Ƥ����ͼƬ

	initgraph(800, 480);//��ʼ����ͼ����
	setbkcolor(WHITE);//���ñ�����ɫΪ��ɫ
	cleardevice();
	loadimage(&imgPika, "Resource_File\\pika.jpg", 200, 200);
	putimage(550, 250, &imgPika);//ƻ��ÿ���½�һ�����ص�
	setcolor(BLACK);
	float accuracy;
	accuracy = 100 * numberOfSuccessWords / length;//�������ȷ��
	TCHAR accuracyArray[20];
	_stprintf_s(accuracyArray, sizeof(accuracyArray), _T("%6.2f"), accuracy);//��accuracyת��Ϊ�ַ������ݣ���������accuracyArray��
	if (accuracy < 50)
	{
		mciSendString("open Resource_File\\endm1.mp3 alias endmusic", NULL, 0, NULL); mciSendString("play endmusic", 0, 0, 0);
		outtextxy(200, 200, "Your accuracy is                %��please continue your effort!");
		outtextxy(315, 200, accuracyArray);
		
	}
	else if (accuracy < 80)
	{
		mciSendString("open Resource_File\\endm2.mp3 alias endmusic", NULL, 0, NULL); mciSendString("play endmusic", 0, 0, 0);
		outtextxy(200, 200, "Your accuracy is                %��good job!");
		outtextxy(315, 200, accuracyArray);
		
	}
	else
	{
		mciSendString("open Resource_File\\endm3.mp3 alias endmusic", NULL, 0, NULL); mciSendString("play endmusic", 0, 0, 0);
		outtextxy(200, 200, "Your accuracy is                 %��excellent!");
		outtextxy(315, 200, accuracyArray);
		
	}
	
	while (true)
	{
		m = GetMouseMsg();
		if (0 <= m.x&&m.x <= 800 && 0 <= m.y&&m.y <= 480 && WM_LBUTTONDOWN == m.uMsg)//�������������������
		{
			mciSendString("stop endmusic", NULL, 0, NULL);//ֹͣ���Ž�����Ч
			mciSendString("close endmusic", NULL, 0, NULL);//��ͣ������Ч
			Main_Interface();
		}
	}
}