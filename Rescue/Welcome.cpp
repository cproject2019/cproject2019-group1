/*********************************************************************************
*����:
Welcome(void) 
*������
ʵ�ֹ��������Ļ���
*�����������ã�
��
*�����������ã�
main(void)
*���ߣ�
����Դ
**********************************************************************************/

#pragma once
#include<graphics.h>
#include<easyx.h>

void Welcome(void)//��ʼ�����������ɺ���
{
	initgraph(800, 480);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(100, 0, TEXT("����"));
	for (int i = 255; i >= 0; i = i - 5)
	{
		settextcolor(RGB(i, i, i));//������ɫ���ݲ���i��ֵ�仯����ɫ�𽥼���
		outtextxy(100, 160, TEXT("Rescue Apples"));
		Sleep(30);//���ñ仯���ʱ��
	}//ʵ��������ɫ��ʱ�������ո���
	Sleep(20);
	for (int i = 0; i <= 255; i = i + 5)
	{
		settextcolor(RGB(i, i, i));//������ɫ���ݲ���i��ֵ�仯����ɫ�𽥱�ǳ
		outtextxy(100, 160, TEXT("Rescue Apples"));
		Sleep(20);//���ñ仯���ʱ��
	}//ʵ��������ɫ��ʱ���𽥱�ǳ��������ʧ
}