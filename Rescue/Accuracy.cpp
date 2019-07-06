#pragma once
#include<graphics.h>
#include<easyx.h>
#include<stdio.h>



/*********************************************************************************
*����:
Accuracy(int * accuracyArray)
*������
��ͼչʾ��ȷ��������Ϣ
*�����������ã�
Main_Interface()
*�����������ã�
Score_Interface(void)
Speed(int * speedArray, int * accuracyArray)
*���ߣ�
����Դ
**********************************************************************************/
void Accuracy(int* accuracyArray)
{
	MOUSEMSG m;
	TCHAR s[10], t[10];
	int i = 0;

	void Laod_Accuracy_Frame(void);

	Laod_Accuracy_Frame();

	/*��ȷ�����������ͼ*/
	for (i = 1; i < 11; i++)
	{
		settextstyle(20, 0, TEXT("����"));
		_stprintf_s(t, _T("%d"), 10 * i);
		outtextxy(65, 410 - 30 * i, t);
		line(100, 90 + 30 * i, 110, 90 + 30 * i);
	}//���y���ϻ���
	for (i = 1; i < 11; i++)
	{
		_stprintf_s(t, sizeof(t), _T("%d"), i);
		outtextxy(100 + 50 * i, 425, t);
		line(100 + 50 * i, 420, 100 + 50 * i, 410);
	}//���x���ϻ���
	for (i = 0; i < 10; i++)
	{
		settextstyle(20, 0, TEXT("����"));
		_stprintf_s(s, sizeof(s), _T("%d"), accuracyArray[i]);
		outtextxy(150 + 50 * i, -3 * accuracyArray[i] + 395, s);
		solidcircle(150 + 50 * i, -3 * accuracyArray[i] + 420, 5);
	}//����׼ȷ�����黭��
	for (i = 0; i<9; i++)
	{
		setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 2);
		line(150 + 50 * i, -3 * accuracyArray[i] + 420, 150 + 50 * (i + 1), -3 * accuracyArray[i + 1] + 420);
	}//�����ڵĵ�����������
	while (true)
	{
		m = GetMouseMsg();
		if (650 <= m.x&&m.x <= 750 && 20 <= m.y&&m.y <= 70 && WM_LBUTTONDOWN == m.uMsg)
		{
			void Main_Interface();
			Main_Interface();
		}
	}//�������λ�ý����жϣ��������ڷ��ذ�ťʱ�����������档
}



/*********************************************************************************
*����:
Laod_Accuracy_Frame(void)
*������
����չʾ��ȷ�ʵĽ���
*�����������ã�
��
*�����������ã�
Accuracy(int * accuracyArray)
*���ߣ�
����Դ
**********************************************************************************/
void Laod_Accuracy_Frame(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextstyle(20, 0, TEXT("����"));
	settextcolor(WHITE);
	setfillcolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 1);
	rectangle(650, 70, 750, 20);
	solidrectangle(650, 70, 750, 20);
	line(100, 450, 100, 50);
	line(20, 420, 700, 420);
	line(100, 50, 85, 65);
	line(100, 50, 115, 65);
	line(700, 420, 685, 435);
	line(700, 420, 685, 405);
	outtextxy(0, 50, TEXT("Accuracy"));
	outtextxy(70, 70, TEXT("%"));
	outtextxy(700, 440, TEXT("Times"));
	outtextxy(680, 50, TEXT("Return"));
	setfillcolor(WHITE);
	outtextxy(90, 425, TEXT("0"));//ͳ��׼ȷ�ʺ��������ʼ��ͼ
}