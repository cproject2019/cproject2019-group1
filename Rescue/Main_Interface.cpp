#pragma once
#include<graphics.h>//��easyxͼ�ο��ͼ
#include<easyx.h>
#include<stdio.h>
#include<conio.h>



/*********************************************************************************
*����:
Main_Interface(void)
*������
ʵ����������ƺ͹���ѡ��
*�����������ã�
Game()
Load_Main_Interface(void)
Score_Interface()
Setting_Interface()
*�����������ã�
Accuracy(int * accuracyArray)
Create_All_Wrodlist(int wordMaxSize)
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
main(void)
Outcome(int numberOfSuccessWords, int length)
Setting_Interface(void)
Start_Game()
*���ߣ�
����Դ
**********************************************************************************/
void Main_Interface(void)
{
	void Game(void);	//��Ϸ����
	void Score_Interface(void);	//�����ٶ���׼ȷ��ͳ�ƺ���
	void Setting_Interface(void);	//������Ϸ��������
	void Load_Main_Interface(void);//�������ʼ������

	Load_Main_Interface();

	while (true)
	{
		MOUSEMSG m;			//���ָ�����
		m = GetMouseMsg();	//��ȡ�������Ϣ
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
	}	//�������λ�ý����ж�
}



/*********************************************************************************
*����:
Load_Main_Interface(void)
*������
����������
*�����������ã�
��
*�����������ã�
Main_Interface(void)
*���������
��
*����ֵ��
��
*���ߣ�
����Դ
**********************************************************************************/
void Load_Main_Interface(void)
{
	initgraph(800, 480);				//��ʼ��������
	setbkcolor(WHITE);					//�趨������ɫ
	cleardevice();						//���ձ�����ɫ�Ա�����ɫ
	setbkcolor(RGB(211, 24, 31));		//����������ɫ
	settextstyle(30, 0, TEXT("����"));	//��ָ��λ������ı�
	IMAGE img;							//����ͼƬ����
	loadimage(&img, "Resource_File\\AppleTree.jpg", 800, 480);//����ͼƬ��������ͼƬ��С
	putimage(0, 0, &img);				//��ָ��λ�ò���ͼƬ
	outtextxy(230, 100, TEXT("Setting"));
	outtextxy(500, 130, TEXT("Game"));
	outtextxy(255, 245, TEXT("Score"));	//��ʼ�����棬��ͼ
}