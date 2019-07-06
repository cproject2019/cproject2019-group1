/*********************************************************************************
*����:
Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount)
*������
��data.txtд�뱾����Ϸ����
*�����������ã�
��
*�����������ã�
Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount) 
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdio.h>
#include"Define_Struct.h"

void Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount)
{
	WRONG_WORDLIST * pointer;
	FILE * fp;

	fopen_s(&fp, "Text_File\\data.txt", "a");						//��data.txt,������ֻд����
	if (NULL == fp)	printf("There is no data.txt");		//��ʽ�ϱ������ļ������ڵķ���

	/*��data.txtд����Ӧ����*/
	fprintf(fp, "%d\t%d\t%d\t%d\t%d", fileRowAmount, length, gameTime, numberOfSuccessWords, targetStringAmount);
	for (pointer = pNewWronglistHead; NULL != pointer; pointer = pointer->next)
	{
		fprintf(fp, "\t%s", pointer->word);
	}
	fprintf(fp, "\n");
	fclose(fp);
}