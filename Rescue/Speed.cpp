#pragma once
#include<graphics.h>
#include<easyx.h>
#include<stdio.h>



/*********************************************************************************
*����:
Speed(int * speedArray, int * accuracyArray)
*������
չʾ�ٶ���Ϣ
*�����������ã�
Accuracy(int *accuracyArray)
*�����������ã�
Score_Interface(void)
*���ߣ�
����Դ
**********************************************************************************/
void Speed(int* speedArray, int* accuracyArray)//�����ٶ�ͳ�ƺ���
{
	MOUSEMSG m;//�������ָ�����
	TCHAR s[10], t[10];
	int i = 0;

	void Laod_Speed_Frame(void);

	Laod_Speed_Frame();

	/*�ٶ����������ͼ*/
	for (i = 1; i < 13; i++)
	{
		settextstyle(20, 0, TEXT("����"));
		_stprintf_s(t, _T("%d"), 5 * i);//������ת��Ϊ�ı����
		outtextxy(65, 410 - 25 * i, t);
		line(100, 410 - 25 * i, 110, 410 - 25 * i);
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
		_stprintf_s(s, sizeof(s), _T("%d"), speedArray[i]);
		outtextxy(150 + 50 * i, -5 * speedArray[i] + 395, s);
		solidcircle(150 + 50 * i, -5 * speedArray[i] + 420, 5);
	}//����׼ȷ�������ṩ�Ĵ����ٶȵ�ֵ����
	for (i = 0; i<9; i++)
	{
		setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 2);
		line(150 + 50 * i, -5 * speedArray[i] + 420, 150 + 50 * (i + 1), -5 * speedArray[i + 1] + 420);
	}//�����ڵĵ���������������
	while (true)
	{
		m = GetMouseMsg();
		if (0 <= m.x&&m.x <= 800 && 0 <= m.y&&m.y <= 480 && WM_LBUTTONDOWN == m.uMsg)
		{
			void Accuracy(int* accuracyArray);
			Accuracy(accuracyArray);
		}
	}//�ж������λ�ã�ʵ���������Ļʱ��ת��ͳ��׼ȷ�ʺ�������
}



/*********************************************************************************
*����:
Laod_Speed_Frame(void)
*������
����չʾ�ٶ����õĽ���
*�����������ã�
��
*�����������ã�
Speed(int * speedArray, int * accuracyArray)
*���ߣ�
����Դ
**********************************************************************************/
void Laod_Speed_Frame(void)
{
	setbkcolor(BLACK);
	cleardevice();
	setcolor(WHITE);
	settextstyle(20, 0, TEXT("����"));
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
	outtextxy(90, 425, TEXT("0"));//�����ٶȺ��������ʼ��ͼ
}