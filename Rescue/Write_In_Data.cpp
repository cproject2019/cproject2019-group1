/*********************************************************************************
*����:
Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords)
*������
�Ӵ��󵥴���������ȡ�ؼ����ַ����Ѳ�����������Ϸ����д��data.txt
*�����������ã�
Count_Data_File_Row()
Rewrite_Wrong_Wordlist(WRONG_WORDLIST *p, int *pTargetStringAmount)
Write_Data_To_File(WRONG_WORDLIST *pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount)
*�����������ã�
Game(void)
*���ߣ�
֣�Ŀ�
**********************************************************************************/
#pragma once
#include"Define_Struct.h"

void Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords)
{
	int fileRowAmount;									//data.txt������
	int targetStringAmount;								//Ŀ���ַ�������Ľڵ����
	int* pTargetStringAmount = &targetStringAmount;
	WRONG_WORDLIST* pNewWronglistHead;					//��д����Ŀ���ַ��������ͷ

	int Count_Data_File_Row(void);						//����data.txt����������
	WRONG_WORDLIST* Rewrite_Wrong_Wordlist(WRONG_WORDLIST* p, int* pTargetStringAmount);//��д���󵥴�������
	void Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount);	//��data.txtд�����ݺ���


	fileRowAmount = Count_Data_File_Row();

	pNewWronglistHead = Rewrite_Wrong_Wordlist(wrongWordlistHead, pTargetStringAmount);	

	/*д���ļ���ʽ��int��Ϸ��� \t int�������� \t int��ʱ��(��) \tint��ȷ���� \t intĿ���ַ������� \t �ַ���1 \t �ַ���2...\n*/
	Write_Data_To_File(pNewWronglistHead, fileRowAmount, length, gameTime, numberOfSuccessWords, targetStringAmount);
}