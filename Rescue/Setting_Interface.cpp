#pragma once
#include<graphics.h>
#include<easyx.h>
#include<stdio.h>
#include<conio.h>



/*********************************************************************************
*����:
Setting_Interface(void)
*������
ʵ�����ý���Ļ��ƺ��������õ�ѡ��ʹ���
*�����������ã�
Load_Setting(int a, int b, int c, int d, int song)
Main_Interface()
Read_In_Setting(int *pInterval, int *pLength, int *pSoundEffect, int *pSong, int *pWordMaxSize)
*�����������ã�
Main_Interface(void)
*���ߣ�
����Դ
**********************************************************************************/
void Setting_Interface(void)
{
	void Main_Interface(void);//�����溯��
	void Read_In_Setting(int* pInterval, int* pLength, int* pSoundEffect, int* pSong, int* pWordMaxSize);//��ȡ���ò���

	int interval, length, soundEffect, song, wordMaxSize;//��ʼ������
	int a = 0, b = 0, c = 0, d = 0;

	Read_In_Setting(&interval, &length, &soundEffect, &song, &wordMaxSize);

	a = -5 * interval + 375;	//����ʱ������������������ٶȿ������ĺ�����ת����ϵ
	b = 8 * length + 110;		//���ʸ�����������䵥�ʸ���������������ת����ϵ
	c = soundEffect;			//����c����Ч����ת����ϵ
	d = 20 * wordMaxSize + 330;	//�����λ�����������������ĺ�����ת����ϵ

	while (true)
	{
		void Load_Setting(int a, int b, int c, int d, int song);//���ý�����غ���
		Load_Setting(a, b, c, d, song);

		MOUSEMSG m = GetMouseMsg();//�������ָ�����
		if (150 <= m.x&&m.x <= 350 && 140 <= m.y&&m.y <= 160 && WM_LBUTTONDOWN == m.uMsg)
		{
			a = m.x;
		}
		else if (150 <= m.x&&m.x <= 350 && 290 <= m.y&&m.y <= 310 && WM_LBUTTONDOWN == m.uMsg)
		{
			b = m.x;
		}
		else if (450 <= m.x&&m.x < 550 && 140 <= m.y&&m.y <= 160 && WM_LBUTTONDOWN == m.uMsg)
		{
			c = 0;
		}
		else if (550 <= m.x&&m.x <= 650 && 140 <= m.y&&m.y <= 160 && WM_LBUTTONDOWN == m.uMsg)
		{
			c = 1;
		}
		else if (450 <= m.x&&m.x <= 650 && 290 <= m.y&&m.y <= 310 && WM_LBUTTONDOWN == m.uMsg)
		{
			d = m.x;
		}
		else if ((m.x - 250)*(m.x - 250) + (m.y - 50)*(m.y - 50) <= 400 && WM_LBUTTONDOWN == m.uMsg)
		{
			song = 1;
		}
		else if ((m.x - 400)*(m.x - 400) + (m.y - 50)*(m.y - 50) <= 400 && WM_LBUTTONDOWN == m.uMsg)
		{
			song = 2;
		}
		else if ((m.x - 550)*(m.x - 550) + (m.y - 50)*(m.y - 50) <= 400 && WM_LBUTTONDOWN == m.uMsg)
		{
			song = 3;
		}//�����������λ����״̬Ϊ�趨�Ĳ�����ֵ
		else if (WM_LBUTTONDOWN == m.uMsg && 730 <= m.x && m.x <= 770 && 380 <= m.y && m.y <= 420)
		{
			Main_Interface();
			system("pause");
		}//�����㵽���ذ�ťʱ�����������档

		FILE* fp;
		fopen_s(&fp, "Text_File\\setting.txt", "w");
		fprintf(fp, "%d\t%d\t%d\t%d\t%d", song, int(-0.2*a + 75), int(0.125*b - 13.75), c, int(0.05*d - 16.5));
		fclose(fp);
	}//��ǰ���������ת��д���ļ�
}



/*********************************************************************************
*����:
Load_Setting(int a, int b, int c, int d, int song) 
*������
ʵ�����ý���Ļ���
*�����������ã�
��
*�����������ã�
Setting_Interface(void) 
*���ߣ�
����Դ
**********************************************************************************/
void Load_Setting(int a, int b, int c, int d, int song)//���ý�����غ���
{
	TCHAR s[10];
	int x = 0, y, z, k;

	BeginBatchDraw();//��ʼ������ͼ��������EndBatchDraw()��������֮ǰ��ͼ�β�������Ļ��
	setbkcolor(BLACK);
	cleardevice();
	setcolor(WHITE);
	settextcolor(WHITE);
	settextstyle(20, 0, TEXT("����"));//�趨�ı���ʽ
	setfillcolor(RED);//�������ɫ
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);//�����߶�����
	circle(250, 50, 20);
	solidcircle(250, 50, 20);
	setfillcolor(BLUE);
	circle(400, 50, 20);
	solidcircle(400, 50, 20);
	setfillcolor(GREEN);
	circle(550, 50, 20);
	solidcircle(550, 50, 20);//���Ƹ����Ŀ���Ȧ
	outtextxy(100, 40, TEXT("Songs"));
	outtextxy(230, 80, TEXT("NO.1"));
	outtextxy(380, 80, TEXT("NO.2"));
	outtextxy(530, 80, TEXT("NO.3"));//��������д������
	rectangle(150, 160, 350, 140);
	rectangle(150, 310, 350, 290);
	rectangle(450, 160, 650, 140);
	rectangle(450, 310, 650, 290);
	line(244.804, 41, 244.804, 59);
	line(244.804, 41, 260.392, 50);
	line(260.392, 50, 244.804, 59);
	line(394.804, 41, 394.804, 59);
	line(394.804, 41, 410.392, 50);
	line(394.804, 59, 410.392, 50);
	line(544.804, 41, 544.804, 59);
	line(544.804, 41, 560.382, 50);
	line(544.804, 59, 560.392, 50);//�����ĸ�������
	outtextxy(150, 185, TEXT("Falling Velocity"));
	outtextxy(150, 335, TEXT("Word Number"));
	outtextxy(450, 185, TEXT("Sound Effect"));
	outtextxy(450, 335, TEXT("Longest Word Length"));
	outtextxy(150, 165, TEXT("0"));
	outtextxy(350, 165, TEXT("100"));
	outtextxy(150, 315, TEXT("5"));
	outtextxy(350, 315, TEXT("30"));
	outtextxy(450, 165, TEXT("Close"));
	outtextxy(650, 165, TEXT("Open"));
	outtextxy(450, 315, TEXT("6"));
	outtextxy(650, 315, TEXT("16"));//������������������д�����֣�����
	x = 0.5*a - 75;
	_stprintf_s(s, sizeof(s), _T("%d"), x);
	outtextxy(a, 110, s);//�������ٶ����ǰ�ť�Ϸ�ʵʱ��ʾ�趨��ֵ
	y = 0.125*b - 13.75;
	_stprintf_s(s, sizeof(s), _T("%d"), y);
	outtextxy(b, 260, s);//�ڵ��ʸ������ǰ�ť�Ϸ�ʵʱ��ʾ�趨��ֵ
	k = 0.05*d - 16.5;
	_stprintf_s(s, sizeof(s), _T("%d"), k);//�ڵ����λ�����ǰ�ť�Ϸ�ʵʱ��ʾ�趨��ֵ
	outtextxy(d, 260, s);
	line(a, 170, a, 130);
	line(a, 170, a + 20, 150);
	line(a + 20, 150, a, 130);
	line(b, 320, b, 280);
	line(b, 320, b + 20, 300);
	line(b + 20, 300, b, 280);
	line(d, 320, d, 280);
	line(d, 320, d + 20, 300);
	line(d + 20, 300, d, 280);//����������

	if (c == 0)
	{
		line(450, 170, 450, 130);
		line(470, 150, 450, 130);
		line(450, 170, 470, 150);
	}
	else
	{
		line(650, 170, 650, 130);
		line(670, 150, 650, 130);
		line(650, 170, 670, 150);
	}//ʵ�ֵ������Ч���������Σ����ǰ�ť��������������ˣ������Ұ�Σ����ǰ�ť�������������Ҷ�

	switch (song)
	{
		case 1:
		{
			setfillcolor(RED);
			circle(250, 50, 20);
			solidcircle(250, 50, 20);
			line(245, 43, 245, 57);
			line(255, 43, 255, 57);
			break;
		}
		case 2:
		{
			setfillcolor(BLUE);
			circle(400, 50, 20);
			solidcircle(400, 50, 20);
			line(395, 43, 395, 57);
			line(405, 43, 405, 57);
			break;
		}
		case 3:
		{
			setfillcolor(GREEN);
			circle(550, 50, 20);
			solidcircle(550, 50, 20);
			line(545, 45, 545, 55);
			line(555, 45, 555, 55);
			break;
		}
	}//���ݲ���c��ֵ������������ֿ�������ͣ����ʼ��ť��ͼ

	rectangle(725, 425, 795, 395);
	outtextxy(730, 400, TEXT("Return"));//���ؼ�����
	EndBatchDraw();//��ɻ�ͼ�����ͼ��
}