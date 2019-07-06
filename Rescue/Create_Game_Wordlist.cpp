/*********************************************************************************
*����:
Create_Game_Wordlist(int wordMaxSize, int length) 
*������
������Ϸ�����б�
*�����������ã�
Count_Data_File_Row()
Count_Wordlist_Length(WORDLIST *pAllWordlistHead)
Create_All_Wrodlist(int wordMaxSize)
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST *, ALL_WORDLIST *)
Read_In_Target_List(int dataFileRowAmount)
Search_Wordlist(TARGET_WORDLIST *, ALL_WORDLIST *)
*�����������ã�
Game(void) 
*���ߣ�
֣�Ŀ�
**********************************************************************************/


#pragma once
#include"Define_Struct.h"

PLAY_WORDLIST* Create_Game_Wordlist(int wordMaxSize, int length)
{
	int allWordlistLength;									//wordlist.txt������
	int dataFileRowAmount;									//data.txt������
	ALL_WORDLIST* pAllWordlistHead;							//����������ͷ
	TARGET_WORDLIST* pTargetHead;							//Ŀ���ַ�������ͷ
	RESULT_WORDLIST* pResultHead;							//ƥ����ҽ����������ͷ
	PLAY_WORDLIST* pPlayWordlistHead;						//��Ϸ��������ͷ

	int Count_Wordlist_Length(WORDLIST* pAllWordlistHead);	//��������ڵ�������
	int Count_Data_File_Row(void);							//����data.txt��������
	ALL_WORDLIST* Create_All_Wrodlist(int wordMaxSize);		//��������������ALL_WORDLIST����
	TARGET_WORDLIST* Read_In_Target_List(int dataFileRowAmount);//��data.txt����Ŀ���ַ���TARGET_WORDLIST����
	RESULT_WORDLIST* Search_Wordlist(TARGET_WORDLIST*, ALL_WORDLIST*);//�ӵ�����������ƥ����Һ���Ŀ���ַ��ĵ��ʺ���
	PLAY_WORDLIST* Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST*, ALL_WORDLIST*);//������Ϸ����������


	pAllWordlistHead = Create_All_Wrodlist(wordMaxSize);			//��������������ALL_WORDLIST

	allWordlistLength = Count_Wordlist_Length(pAllWordlistHead);	//����ALL_WORDLIST�ڵ���

	dataFileRowAmount = Count_Data_File_Row();						//����data.txt������

	pTargetHead = Read_In_Target_List(dataFileRowAmount);			//����Ŀ���ַ���TARGET_WORDLIST,��û���ַ�����û��data�ļ�������NULL

	pResultHead = Search_Wordlist(pTargetHead, pAllWordlistHead);	//��Sunday�㷨ƥ�京��Ŀ���ַ���TRGET_WORDLIST�ĵ��ʣ���û�У�����NULL

	pPlayWordlistHead = Create_Play_Wordlist(allWordlistLength, length, pResultHead, pAllWordlistHead);	//������Ϸ�����б�PLAY_WORDLIST

	return pPlayWordlistHead;
}
