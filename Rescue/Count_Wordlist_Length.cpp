/*********************************************************************************
*����:
Count_Wordlist_Length(WORDLIST * p)
*������
������������ڵ���
*�����������ã�
��
*�����������ã�
Create_Game_Wordlist(int wordMaxSize, int length)
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdio.h>
#include"Define_Struct.h"

int Count_Wordlist_Length(WORDLIST* p)
{
	WORDLIST* pointer = p;					//ָ���ʼ��Ϊ�׽ڵ�
	if (NULL == pointer)	return 0;
	while (NULL != pointer->next)
	{
		pointer = pointer->next;			//ָ��ĩ�ڵ�
	}
	return pointer->num;
}