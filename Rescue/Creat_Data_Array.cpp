/*********************************************************************************
*����:
Creat_Data_Array(int * speedArray, int * accuracyArray, int gameTimeAmount)
*������
��data.txt�ж�ȡ���ʮ����Ϸ�����ݴ����������鴢���ٶȡ���ȷ����Ϣ
*�����������ã�
��
*�����������ã�
Score_Interface(void)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdio.h>

void Creat_Data_Array(int* speedArray, int* accuracyArray, int gameTimeAmount)
{
	FILE* fp;
	fopen_s(&fp, "Text_File\\data.txt", "r");
	if (10 < gameTimeAmount)//���ֻ��ȡ���ʮ������
	{
		for (int i = 0; i < gameTimeAmount - 10;)
		{
			if ('\n' == fgetc(fp))	i++;
		}
	}
	for (int i = 0; i<10 && i<gameTimeAmount; i++)
	{
		int temp = 0, tempLength, tempGameTime, numberOfSuccessWords;
		fscanf_s(fp, "%d", &temp);
		fscanf_s(fp, "%d%d%d ", &tempLength, &tempGameTime, &numberOfSuccessWords);
		*(speedArray+i) = (int)(60 * tempLength / tempGameTime);//���������ٶ����飬��λ����/min
		*(accuracyArray+i) = (int)(100 * numberOfSuccessWords / tempLength);//������ȷ�����飬��λ��%
		char tempchar = fgetc(fp);
		while ('\n' != tempchar && EOF != tempchar)
		{
			tempchar = fgetc(fp);
		}
	}
	fclose(fp);
}