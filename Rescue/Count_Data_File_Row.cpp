/*********************************************************************************
*����:
Count_Data_File_Row(void)
*������
����data.txt������
*�����������ã�
��
*�����������ã�
Create_Game_Wordlist(int wordMaxSize, int length)
Score_Interface(void)
Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdio.h>
#include"Define_Struct.h"

int Count_Data_File_Row(void)
{
	FILE *fp = NULL;
	int fileRow = 1;										//�ļ�������ʼ��
	
	fopen_s(&fp, "Text_File\\data.txt", "a+");							//��data.txt���������ڣ�����֮
	if (NULL == fp)		printf("There is no data.txt");		//��ʽ�ϱ������ļ������ڵķ���
	while (!feof(fp))
	{
		if ('\n' == fgetc(fp))	fileRow++;					//����'\n'������+1
	}
	fclose(fp);
	return fileRow;
}
